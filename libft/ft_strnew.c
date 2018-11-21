/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:28:19 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 19:28:20 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	new = NULL;
	new = (char*)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	new[i] = '\0';
	return (new);
}
