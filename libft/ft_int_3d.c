/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:45:44 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	***ft_int_3d(int it, int jt, int kt)
{
	int	***tab;
	int	i;

	i = 0;
	tab = NULL;
	tab = (int***)malloc(sizeof(int**) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = ft_int_2d(jt, kt);
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
