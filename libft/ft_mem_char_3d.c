/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_char_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:46:42 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_mem_char_3d(int it, int jt, int kt, int c)
{
	char	***tab;
	int		i;

	i = 0;
	tab = NULL;
	tab = (char***)malloc(sizeof(char**) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = ft_mem_char_2d(jt, kt, c);
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
