/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:55:45 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 03:58:07 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_in_tab(char **tab, int size, char *element)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(new[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(new[size] = ft_strdup(element)))
		return (NULL);
	return (new);
}
