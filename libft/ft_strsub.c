/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:58:30 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 20:41:10 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if ((new = ft_strnew(len)))
	{
		while (i < len)
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (0);
}
