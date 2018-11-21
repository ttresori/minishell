/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:15:20 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/30 04:57:26 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrspace(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
	ft_putchar(' ');
}
