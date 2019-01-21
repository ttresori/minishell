/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:34:32 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 17:46:21 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *m, const char *n, size_t len)
{
	unsigned	int	i;
	unsigned	int	pos;
	size_t			slen;

	i = 0;
	slen = ft_strlen(n);
	if (slen == 0)
		return ((char*)m);
	while (m[i] && (slen + i) <= len)
	{
		pos = 0;
		while (n[pos] == m[pos + i])
		{
			if (pos == (slen - 1))
				return ((char*)m + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
