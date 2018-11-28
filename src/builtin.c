/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:51:19 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 18:11:29 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	do_echo(t_file *s_file)
{
	int i;
	int i2;

	i = 1;
	i2 = 0;
	while (s_file->comm[i] != NULL)
	{
		while (s_file->comm[i][i2] != '\0')
		{
			while (s_file->comm[i][i2] == '"')
				i2++;
			ft_putchar(s_file->comm[i][i2]);
			i2++;
		}
		i++;
		i2 = 0;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

int		check_env_builtin(t_file *s_file)
{
	if (ft_strncmp(s_file->comm[0], "env", 3) == 0)
	{
		put_env(s_file->env, s_file->size_env);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "unsetenv", 8) == 0)
	{
		unset_env(s_file);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "setenv", 6) == 0)
	{
		do_set_env(s_file);
		return (1);
	}
	return (0);
}

int		check_own_builtin(t_file *s_file)
{
	if (ft_strncmp(s_file->comm[0], "cd", 2) == 0)
	{
		do_cd(s_file);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "echo", 4) == 0)
	{
		do_echo(s_file);
		return (1);
	}
	if (check_env_builtin(s_file) == 1)
		return (1);
	if (ft_strncmp(s_file->comm[0], "exit", 4) == 0)
		free_struct(s_file);
	return (0);
}
