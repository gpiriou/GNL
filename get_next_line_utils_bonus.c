/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:50:12 by gpiriou           #+#    #+#             */
/*   Updated: 2021/02/13 10:50:29 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

long int		f_tab(struct s_list **tab, char *str)
{
	int i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	while (tab[i])
	{
		free(tab[i]->temp);
		free(tab[i++]);
	}
	free(tab[i]);
	free(tab);
	return (0);
}

char			*ft_strjoin(char *s1, char *s2, int n)
{
	char	*s3;
	char	*save;
	int		s1_len;
	int		i;

	if (n > 0)
	{
		if (!s1 || !s2)
			return (NULL);
		if (!(s3 = malloc((f_tab(0, s1) + f_tab(0, s2) + 1) * sizeof(char))))
			return (NULL);
		*s3 = '\0';
		save = ft_strjoin(ft_strjoin(s3, s1, 0), s2, 0);
		n == 3 ? free(s2) : 0;
		return (save);
	}
	else
	{
		s1_len = f_tab(NULL, s1);
		i = -1;
		while (s2[++i])
			s1[s1_len + i] = s2[i];
		s1[s1_len + i] = 0;
		return (s1);
	}
}

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	s_unsigned;
	char			*str;

	if (!s)
		return (NULL);
	s_unsigned = (unsigned int)f_tab(NULL, s);
	if (!(str = malloc((len + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < len && start < s_unsigned)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strchr(char *s, int c)
{
	unsigned char	char_c;
	unsigned int	i;

	char_c = (unsigned char)c;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == char_c)
			return (&s[i]);
		i++;
	}
	if (s[i] == char_c)
		return (&s[i]);
	else
		return (NULL);
}

char			*ft_strndup(char *s1, int n)
{
	int		i;
	char	*s1_dup;

	i = 0;
	if (!(s1_dup = malloc((n + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] && i < n)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
