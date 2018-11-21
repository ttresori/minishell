/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:13:23 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 21:22:41 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	size_t	i;

	if (!s)
		return (0);
	new = NULL;
	i = 0;
	new = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (0);
	while (s[i] != '\0')
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
