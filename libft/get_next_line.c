/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 02:30:34 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/21 02:45:19 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		real_return(int fd, t_struct *s, char ***line)
{
	if (s->ret < 0)
		return (-1);
	if (ft_strlen(s->tmp) > 0)
	{
		**line = s->tmp;
		ft_strdel(&s->stock[fd]);
		s->stock[fd] = NULL;
		return (1);
	}
	**line = NULL;
	ft_strdel(&s->stock[fd]);
	s->stock[fd] = NULL;
	ft_strdel(&s->tmp);
	return (0);
}

void			free_fd(int fd, t_struct *s)
{
	if (fd == -2)
		ft_strdel(&s->stock[0]);
}

int				get_next_line(const int fd, char **line)
{
	static t_struct s;

	free_fd(fd, &s);
	if (fd < 0 || fd > 5000 || !line
	|| (!(s.stock[fd] = (!s.stock[fd]) ? ft_strnew(BUFF_SIZE) : s.stock[fd]))
	|| (!(s.tmp = ft_strcpy(ft_strnew(BUFF_SIZE), s.stock[fd]))))
		return (-1);
	while (!(ft_strchr(s.tmp, '\n')))
	{
		if ((s.ret = read(fd, s.buf, BUFF_SIZE)) < 1)
			return (real_return(fd, &s, &line));
		s.buf[s.ret] = '\0';
		if (!(s.str = ft_strjoin(s.tmp, s.buf)))
			return (-1);
		ft_strdel(&s.tmp);
		s.tmp = s.str;
	}
	if (!(*line = ft_strsub(s.tmp, 0, ft_strlen(s.tmp) -
	ft_strlen(ft_strchr(s.tmp, '\n')))))
		return (-1);
	if (ft_strchr(s.tmp, '\n'))
		s.stock[fd] = ft_strncpy(s.stock[fd], ft_strchr(s.tmp, '\n') +
		1, BUFF_SIZE);
	ft_strdel(&s.tmp);
	return (1);
}
