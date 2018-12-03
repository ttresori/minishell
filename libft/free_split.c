/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:22:53 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/01 13:23:30 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_split(char **split)
{
    int	i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	split = NULL;
	return (split);
}
