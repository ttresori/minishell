/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:46:36 by ttresori          #+#    #+#             */
/*   Updated: 2016/11/30 20:51:28 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	*s12;
	unsigned char	*s22;

	i = 0;
	s12 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (s12[i] != '\0' && s22[i] != '\0')
	{
		if (s12[i] != s22[i])
			return (s12[i] - s22[i]);
		i++;
	}
	if (s12[i] == s22[i])
		return (0);
	return (s12[i] - s22[i]);
}
