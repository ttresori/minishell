/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:55:04 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 05:39:07 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	add_new(t_file *s_file)
{
	char	*tmp;
	char	**new_env;

	tmp = NULL;
	new_env = NULL;
	if (!(tmp = ft_strdup(s_file->comm[1])))
		return ;
	new_env = add_in_tab(s_file->env, s_file->size_env, tmp);
	free_env(s_file);
	s_file->env = new_env;
	s_file->size_env++;
	free(tmp);
}

int		search_env(char **env, int size, char *element)
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

void	unset_env(t_file *s_file)
{
	int		pos;
	char	**search;
	char	**new_env;

	pos = 0;
	new_env = NULL;
	if (s_file->comm[1] == NULL)
		return ;
	search = ft_strsplit(s_file->comm[1], '=');
	pos = search_env(s_file->env, s_file->size_env, search[0]);
	if (pos == -1)
	{
		search = free_split(search);
		return ;
	}
	new_env = remove_in_tab(s_file->env, s_file->size_env, pos);
	free_env(s_file);
	search = free_split(search);
	s_file->env = new_env;
	s_file->size_env--;
}

void	do_set_env(t_file *s_file)
{
	int		i;
	int		find;
	char	**search;

	i = 0;
	find = 0;
	if (s_file->comm[1] == NULL)
		return ;
	search = ft_strsplit(s_file->comm[1], '=');
	if (search[1] == NULL)
	{
		search = free_split(search);
		return ;
	}
	if ((find = search_env(s_file->env, s_file->size_env, search[0])) > -1)
	{
		free(s_file->env[find]);
		s_file->env[find] = ft_strdup(s_file->comm[1]);
	}
	else
		add_new(s_file);
	search = free_split(search);
}

void	put_env(char **env, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(env[i++]);
}
