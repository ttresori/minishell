/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/04 02:24:08 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_char_2d(int it, int jt)
{
	int		i;
	char	**tab;

	i = 0;
	tab = (char**)malloc(sizeof(char*) * (it + 1));
	if (!tab)
		return (NULL);
	while (i < it)
	{
		tab[i] = (char*)ft_memalloc(sizeof(char) * (jt + 1));
		if (tab[i] == NULL)
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
