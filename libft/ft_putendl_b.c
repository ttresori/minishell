/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 22:08:04 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/12 16:58:18 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_b(const char *s)
{
	if (!s)
		return ;
	ft_putstr(BLUE);
	ft_putstr(s);
	ft_putstr(NORMAL);
	ft_putchar('\n');
}
