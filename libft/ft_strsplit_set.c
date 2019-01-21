/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:35:29 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/01 13:25:21 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(const char *s, char const *delims)
{
	const char	*start;

	start = s;
	while (!ft_strchr(delims, *s))
		++s;
	return (s - start);
}

static int		ft_word_count(const char *s, char const *delims)
{
	int		words;

	words = 0;
	while (*s)
	{
		if (!ft_strchr(delims, *s) && (ft_strchr(delims, s[1]) || s[1] == 0))
			++words;
		++s;
	}
	return (words);
}

static void		free_split_set(char **tab, int last)
{
	while (last-- > 0)
		free(tab[last]);
	free(tab);
}

char			**ft_strsplit_set(char const *s, char const *delims)
{
	char		**split;
	char const	*start;
	int			i;
	int			words;

	if (!s || !(split = (char **)malloc(sizeof(*split)
					* ((words = ft_word_count(s, delims)) + 1))))
		return (NULL);
	start = s;
	split[words] = NULL;
	i = 0;
	while (i < words)
	{
		while (ft_strchr(delims, *s))
			++s;
		if (!(split[i++] = ft_strsub(start, s - start, ft_word_len(s, delims))))
		{
			free_split_set(split, i);
			return (NULL);
		}
		while (!ft_strchr(delims, *s))
			++s;
	}
	return (split);
}
