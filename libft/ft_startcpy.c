/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 21:14:46 by ttresori          #+#    #+#             */
/*   Updated: 2017/09/30 20:37:36 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_startcpy(char *dest, const char *src, int start)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[start++] = src[i++];
	}
	dest[i] = '\0';
	return (dest);
}
