/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putntab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 00:32:13 by ttresori          #+#    #+#             */
/*   Updated: 2017/07/03 20:34:14 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putntab(const char *str, size_t stop)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i] && i != stop)
			ft_putchar(str[i++]);
		ft_putchar(9);
	}
}
