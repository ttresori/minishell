/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_2d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmand <carmand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/11 02:00:04 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_2d(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
		i++;
	while (j < i)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}
