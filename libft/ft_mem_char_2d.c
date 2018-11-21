/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem_char_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/04/25 20:46:19 by carmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mem_char_2d(int it, int jt, int c)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = (char*)malloc(sizeof(char) * (jt + 1));
		if (tab[i] == NULL)
			return (NULL);
		tab[i] = ft_memset(tab[i], c, jt);
		tab[i][jt] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
