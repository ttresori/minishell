/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:18:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 03:02:01 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	print_prompt()
{
	char buf[255];

	ft_putstr(GREEN);
	ft_putstr(getcwd(buf, 255));
	ft_putstr("?> ");
	ft_putstr(NORMAL);
}

void	exec_comm(t_file *s_file, char *bin)
{
	pid_t father;

	father = fork();
	if (father > 0)
		wait(0);
	if (father == 0)
	{
		execve(bin, s_file->comm, s_file->env);
		ft_putstr_fd("minishell: command not found: ", 2);
	}
}

int		check_own_builtin(t_file *s_file)
{
	if (ft_strncmp(s_file->comm[0], "echo", 4) == 0)
	{
		do_echo(s_file);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "env", 3) == 0)
	{
		put_env(s_file->env, s_file->size_env);
		return (1);
	}
/*	if (ft_strncmp(s_file->comm[0], "cd", 2) == 0)
	{
		do_cd(s_file);
		return (1);
		}*/
	if (ft_strncmp(s_file->comm[0], "setenv", 6) == 0)
	{
		do_set_env(s_file);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "pwd", 3) == 0)
	{
		ft_putendl(s_file->pwd);
		return (1);
	}
	if (ft_strncmp(s_file->comm[0], "exit", 4) == 0)
		free_struct(s_file);
	return (0);
}

int		check_builtin(t_file *s_file)
{
	int i;
	char *tmp;
	char *tmp2;
	
	i = 0;
	tmp = NULL;
	if (check_own_builtin(s_file) == 1)
		return (0);
	while (s_file->path[i] != NULL)
	{
		if (!(tmp2 = ft_strjoin(s_file->path[i], "/")))
			return (-1);
		if (!(tmp = ft_strjoin(tmp2, s_file->comm[0])))
			return (-1);
		if (access(tmp, F_OK) == 0)
		{
			exec_comm(s_file, tmp);
			free(tmp);
			free(tmp2);
			return (1);
		}
		i++;
		free(tmp);
		free(tmp2);
	}
	return (0);
}
