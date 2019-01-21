/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 10:50:42 by ttresori          #+#    #+#             */
/*   Updated: 2017/10/30 04:51:15 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsdup(const char *src, int start, int stop)
{
	int		i;
	char	*dup;

	i = 0;
	if (!(dup = (char *)malloc(sizeof(char) * ft_strlen(src) + 1)))
		return (0);
	else
	{
		while (src[start] != '\0' && start < stop)
		{
			dup[i] = src[start];
			i++;
			start++;
		}
		dup[i] = '\0';
		return (dup);
	}
}
