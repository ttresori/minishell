/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_char_3d.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by carmand           #+#    #+#             */
/*   Updated: 2017/10/30 04:51:43 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_char_3d(char ***tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
		i++;
	while (i > 0)
	{
		ft_free_char_2d(tab[i]);
		i--;
	}
	free(tab);
}
