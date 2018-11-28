/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 02:30:42 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 17:55:31 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct	s_struct
{
	char		*stock[5000];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	char		*str;
	int			ret;
}				t_struct;

int				get_next_line(const int fd, char **line);

#endif
