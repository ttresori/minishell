/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:12:19 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 18:12:44 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_env(char **env, int size, char *element)
{
	int pos;

	pos = 0;
	while (pos < size)
	{
		if (ft_strncmp(element, env[pos], ft_strlen(element)) == 0)
			return (pos);
		pos++;
	}
	return (-1);
}
