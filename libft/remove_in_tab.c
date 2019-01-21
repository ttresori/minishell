/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_in_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 05:32:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 05:32:21 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**remove_in_tab(char **tab, int size, int pos)
{
	int		i;
	int		i2;
	char	**new;

	i = 0;
	i2 = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size))))
		return (NULL);
	while (tab[i2] != NULL)
	{
		if (i2 != pos)
		{
			if (!(new[i] = ft_strdup(tab[i2])))
				return (NULL);
			i++;
		}
		free(tab[i2]);
		i2++;
	}
	new[i] = NULL;
	free(tab);
	return (new);
}
