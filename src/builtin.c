/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:51:19 by ttresori          #+#    #+#             */
/*   Updated: 2019/01/21 03:18:03 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	do_echo(t_file *s_file)
{
	int i;

	i = 1;
	while (s_file->comm[i] != NULL)
	{
		ft_putstr(s_file->comm[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

int		check_env_builtin(t_file *s_file)
{
	if (ft_strcmp(s_file->comm[0], "env") == 0)
	{
		put_env(s_file->env, s_file->size_env);
		return (1);
	}
	if (ft_strcmp(s_file->comm[0], "unsetenv") == 0)
	{
		unset_env(s_file);
		return (1);
	}
	if (ft_strcmp(s_file->comm[0], "setenv") == 0)
	{
		do_set_env(s_file);
		return (1);
	}
	return (0);
}

int		check_own_builtin(t_file *s_file)
{
	if (ft_strcmp(s_file->comm[0], "cd") == 0)
	{
		do_cd(s_file);
		return (1);
	}
	if (ft_strcmp(s_file->comm[0], "echo") == 0)
	{
		do_echo(s_file);
		return (1);
	}
	if (check_env_builtin(s_file) == 1)
		return (1);
	if (ft_strcmp(s_file->comm[0], "exit") == 0)
		free_struct(s_file);
	return (0);
}
