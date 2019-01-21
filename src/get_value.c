/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 03:18:46 by ttresori          #+#    #+#             */
/*   Updated: 2019/01/21 03:18:49 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int		get_home(t_file *s_file)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	i = -1;
	if (-1 != (i = search_env(s_file->env, s_file->size_env, "HOME=")))
	{
		if ((tmp = ft_strsplit(s_file->env[i], '=')))
		{
			free(s_file->home);
			if (!(s_file->home = ft_strdup(tmp[1])))
				return (0);
			free_split(tmp);
			return (1);
		}
	}
	if (s_file->home)
		return (1);
	return (0);
}

int		get_path(t_file *s_file)
{
	int		i;
	char	**tmp;

	i = search_env(s_file->env, s_file->size_env, "PATH=");
	if (i < 0)
	{
		s_file->path = NULL;
		return (1);
	}
	if (!(s_file->path = ft_strsplit(s_file->env[i], ':'))
	|| !(tmp = ft_strsplit(s_file->path[0], '=')))
		return (0);
	free(s_file->path[0]);
	if (!(s_file->path[0] = ft_strdup(tmp[1])))
		return (0);
	i = 0;
	while (tmp[i] != NULL)
		ft_strdel(&tmp[i++]);
	i = 0;
	while (s_file->path[i])
		i++;
	s_file->size_path = i + 1;
	free(tmp);
	return (1);
}

int		place_home(t_file *s_file, int i)
{
	char	*tmp3;
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	tmp2 = NULL;
	if (!(get_home(s_file)))
		return (1);
	tmp3 = ft_strchr(s_file->comm[i], '~');
	if (!(tmp = ft_strndup(s_file->comm[i], ft_strlen(s_file->comm[i])
	- ft_strlen(tmp3)))
	|| !(tmp2 = ft_strjoin(tmp, s_file->home)))
		return (0);
	free(tmp);
	if (!(tmp = ft_strjoin(tmp2, &tmp3[1])))
		return (0);
	free(tmp2);
	free(s_file->comm[i]);
	s_file->comm[i] = tmp;
	return (1);
}
