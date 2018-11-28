/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:18:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 14:05:48 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	print_prompt(t_file *s_file)
{
	ft_putstr(GREEN);
	ft_putstr(s_file->pwd);
	ft_putstr("?> ");
	ft_putstr(NORMAL);
}

void	print_error_no_var_env(char *error)
{
	ft_putstr(BLUE);
	ft_putstr_fd("Set the [", 2);
	ft_putstr_fd(error, 2);
	ft_putstr_fd("]", 2);
	ft_putendl_fd(" see setenv", 2);
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
		if (bin != NULL)
			execve(bin, s_file->comm, s_file->env);
		else
			execve(s_file->comm[0], s_file->comm, s_file->env);
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(s_file->comm[0], 2);
		exit(0);
	}
}

int		check_builtin(t_file *s_file)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	tmp = NULL;
	if (access(s_file->comm[0], F_OK) == 0)
	{
		exec_comm(s_file, NULL);
		return (1);
	}
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
		free(tmp);
		free(tmp2);
		i++;
	}
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(s_file->comm[0], 2);
	return (0);
}
