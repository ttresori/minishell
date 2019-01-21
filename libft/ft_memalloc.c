/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:58:30 by ttresori          #+#    #+#             */
/*   Updated: 2016/12/01 15:18:22 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tab;
	size_t	i;

	tab = NULL;
	i = 0;
	tab = malloc(size);
	if (tab == NULL)
		return (0);
	while (i < size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
