/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:43:39 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	**ft_int_2d(int it, int jt)
{
	int	i;
	int	**tab;

	i = 0;
	tab = (int**)malloc(sizeof(int*) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = (int*)ft_memalloc(sizeof(int) * (jt + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
