/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpiriou <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:16:22 by gpiriou           #+#    #+#             */
/*   Updated: 2021/02/13 10:49:35 by gpiriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_list {
	int		fd;
	char	*temp;
}				t_list;

int				get_next_line(int fd, char **line);
long int		f_tab(struct s_list **tab, char *str);
char			*ft_strjoin(char *s1, char *s2, int n);
char			*ft_strndup(char *s1, int n);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2, int n);
char			*ft_strndup(char *s1, int n);
char			*ft_strchr(char *s, int c);
char			*ft_substr(char *s, unsigned int start, size_t len);

#endif
