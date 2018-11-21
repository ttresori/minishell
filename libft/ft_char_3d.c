/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:32:15 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:43:09 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_char_3d(int it, int jt, int kt)
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
		tab[i] = ft_char_2d(jt, kt);
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
