/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:15:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/24 03:41:02 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void    free_line(t_file *s_file)
{
	int i;

	i = 0;
	if (s_file->size_comm > 0)
		free(s_file->comm);
	s_file->size_comm = 0;
	if (s_file->opt != NULL)
	{
		while (s_file->opt != NULL)
		{
			free(s_file->opt[i]);
			i++;
		}
		free(s_file->opt);
		s_file->size_opt = 0;
	}
	i = 0;
	if (s_file->arg[i] != NULL)
	{
		while (s_file->arg[i] != NULL)
		{
			free(s_file->arg[i]);
			i++;
		}
		s_file->size_arg = 0;
		free(s_file->arg);
	}
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
}

void    free_struct(t_file *s_file)
{
    int	i;

    i =	0;

	if (s_file->size_comm > 0)
		free(s_file->comm);
	while (i < s_file->size_opt)
		free(s_file->opt[i++]);
	if (s_file->opt)
		free(s_file->opt);
	s_file->size_opt = 0;
	i = 0;
	while (i < s_file->size_arg)
		free(s_file->arg[i++]);
	if (s_file->arg)
		free(s_file->arg);
	s_file->size_arg = 0;
	while (i < s_file->size_env)
	{
		ft_strdel(&s_file->env[i]);
        i++;
	}
	i = 0;
	while (s_file->path[i] != NULL)
	{
		ft_strdel(&s_file->path[i]);
		i++;
	}
	free(s_file->path);
	free(s_file->env);
	free(s_file);
	exit(0);
}
