/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 01:15:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/21 04:04:07 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void    free_line(t_file *s_file)
{
	if (s_file->size_comm > 0)
	{
		free(s_file->comm);
		s_file->size_comm = 0;
	}
	if (s_file->size_arg > 0)
	{
		free(s_file->arg);
		s_file->size_arg = 0;
	}
	if (s_file->size_opt > 0)
	{
		free(s_file->opt);
		s_file->size_opt = 0;
	}
}

void	free_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void    free_struct(t_file *s_file)
{
    int	i;

    i =	0;
    if (s_file->size_comm > 0)
        ft_strdel(&s_file->comm);
    if (s_file->size_arg > 0)
        ft_strdel(&s_file->arg);
    if (s_file->size_opt > 0)
        ft_strdel(&s_file->opt);
	while (i < s_file->size_env)
	{
		ft_strdel(&s_file->env[i]);
        i++;
	}
	i = 0;
	while (i < s_file->size_path)
	{
		ft_strdel(&s_file->path[i]);
		i++;
	}
	free(s_file->path);
	free(s_file->env);
	free(s_file);
	exit(0);
}
