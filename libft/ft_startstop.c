/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startstop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/02 00:32:13 by ttresori          #+#    #+#             */
/*   Updated: 2017/07/03 20:35:44 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_startstop(const char *str, size_t start, size_t stop)
{
	if (str)
	{
		while (str[start] && start != stop)
			ft_putchar(str[start++]);
	}
}
