/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:18:32 by gpiriou           #+#    #+#             */
/*   Updated: 2021/02/13 17:20:01 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char				*find_newline(char *str, struct s_list *t_list)
{
	char	*nl_str;
	char	*newline;
	char	*save;

	nl_str = NULL;
	save = NULL;
	if ((newline = ft_strchr(t_list->temp, '\n')))
	{
		save = t_list->temp;
		nl_str = ft_substr(t_list->temp, 0, newline - t_list->temp);
	}
	else if ((newline = ft_strchr(str, '\n')))
	{
		save = str;
		nl_str = ft_substr(str, 0, newline - str);
	}
	if (newline)
	{
		t_list->temp = ft_strndup(newline + 1, f_tab(NULL, newline + 1));
		free(save);
	}
	else if (str)
		t_list->temp = str;
	return (nl_str);
}

int					read_tab(int fd, int re, struct s_list *t_list, char **line)
{
	char buff[BUFFER_SIZE + 1];
	char *str;

	str = NULL;
	while (!(*line = find_newline(str, t_list)))
	{
		if (re <= 0)
		{
			*line = t_list->temp ? t_list->temp : str;
			if (*line == t_list->temp)
				t_list->temp = NULL;
			break ;
		}
		if ((re = read(fd, buff, BUFFER_SIZE)) > 0)
		{
			str = ft_strndup(buff, re);
			if (t_list->temp)
			{
				str = ft_strjoin(t_list->temp, str, 3);
				free(t_list->temp);
				t_list->temp = NULL;
			}
		}
	}
	return (re);
}

struct s_list		**realloc_tab(int fd, struct s_list **tab)
{
	struct s_list	**tab2;
	int				i;

	i = 0;
	while (tab && tab[i])
		i++;
	i = tab ? i + 1 : 1;
	if (!(tab2 = malloc(sizeof(struct s_list *) * (i + 1))))
		return ((struct s_list **)f_tab(tab, NULL));
	i = -1;
	while (tab && tab[++i])
		tab2[i] = tab[i];
	i = tab ? i : 0;
	if (!(tab2[i] = malloc(sizeof(struct s_list))))
		return ((struct s_list **)f_tab(tab2, NULL));
	tab2[i]->fd = fd;
	tab2[i]->temp = NULL;
	tab2[i + 1] = NULL;
	free(tab);
	return (tab2);
}

int					find_fd(int fd, int ret, struct s_list ***tab, char **line)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		if ((*tab)[i]->fd == fd)
		{
			ret = read_tab(fd, ret, (*tab)[i], line);
			return (ret);
		}
		i++;
	}
	if (!(*tab = realloc_tab(fd, *tab)))
		return (-1);
	ret = find_fd(fd, ret, tab, line);
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static struct s_list	**tab;
	char					buff[1];
	int						ret;
	int						i;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || read(fd, buff, 0) < 0)
		return (-1);
	*line = NULL;
	if (!tab && !(tab = realloc_tab(fd, tab)))
		return (-1);
	ret = find_fd(fd, 1, &tab, line);
	if (*line == NULL)
		*line = ft_strndup("", 0);
	if (ret > 0)
		return (1);
	else
	{
		i = 0;
		while (tab[i] && tab[i]->temp == NULL)
			i++;
		if (ret < 0 || tab[i] == NULL)
			tab = (struct s_list **)f_tab(tab, NULL);
		return (ret < 0 ? -1 : 0);
	}
}
