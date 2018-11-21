/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:42:52 by ttresori          #+#    #+#             */
/*   Updated: 2016/12/01 14:15:59 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*dstc;
	size_t	i;

	if (dest == src)
		return (dest);
	i = -1;
	srcc = (char *)src;
	dstc = (char *)dest;
	if (srcc < dstc)
		while ((int)(--n) >= 0)
			*(dstc + n) = *(srcc + n);
	else
		while (++i < n)
			*(dstc + i) = *(srcc + i);
	return (dest);
}
