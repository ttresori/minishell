/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:15:52 by ttresori          #+#    #+#             */
/*   Updated: 2019/01/21 03:24:50 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	free_env(t_file *s_file)
{
	int		i;

	i = 0;
	while (i < s_file->size_env)
	{
		ft_strdel(&s_file->env[i]);
		i++;
	}
	free(s_file->env);
}

char	**free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
		free(split[i++]);
	free(split);
	split = NULL;
	return (split);
}

void	free_line(t_file *s_file)
{
	int		i;

	i = 0;
	while (i < s_file->size_comm)
	{
		ft_strdel(&s_file->comm[i]);
		i++;
	}
	free(s_file->comm);
}

void	free_tmp(char ***tmp1, char ***tmp2)
{
	free_split(*tmp1);
	free_split(*tmp2);
}

void	free_struct(t_file *s_file)
{
	int	i;

	i = 0;
	while (i < s_file->size_env)
	{
		ft_strdel(&s_file->env[i]);
		i++;
	}
	if (s_file->env != NULL)
		free(s_file->env);
	i = 0;
	if (s_file->path != NULL)
	{
		free_split(s_file->path);
	}
	i = 0;
	while (s_file->comm[i] != NULL)
		ft_strdel(&s_file->comm[i++]);
	free(s_file->pwd);
	free(s_file->old_pwd);
	free(s_file->comm);
	exit(0);
}
