/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:55:45 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 16:14:58 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**add_in_tab(char **tab, int size, char *element)
{
	int		i;
	char	**new;

	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size + 2))))
		return (NULL);
	if (tab[0] == NULL)
	{
		free(new);
		return (new);
	}
	while (i < size)
	{
		if (!(new[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(new[size] = ft_strdup(element)))
		return (NULL);
	new[size + 1] = NULL;
	return (new);
}
