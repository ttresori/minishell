/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:06:45 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 20:56:57 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_len(int n)
{
	unsigned int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n /= 10)
		len++;
	return (len);
}

static void			to_string(char **s, unsigned int *i, unsigned int n)
{
	if (n == 0)
		(*s)[0] = '0';
	(*i)--;
	while (n > 0)
	{
		(*s)[*i] = '0' + (n % 10);
		n /= 10;
		(*i)--;
	}
}

char				*ft_itoa(int n)
{
	int				sign;
	char			*s;
	unsigned int	i;

	s = NULL;
	i = get_len(n);
	if ((s = ft_strnew(i)))
	{
		if (n == 0)
		{
			to_string(&s, &i, n);
			return (s);
		}
		sign = 1;
		if (n < 0)
		{
			n = -n;
			sign = -1;
		}
		to_string(&s, &i, n);
		if (sign < 0)
			s[i] = '-';
	}
	return (s);
}
