/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:18:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 01:31:54 by ttresori         ###   ########.fr       */
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

void	put_env(char **env, int size)
{
	int i;

	i = 0;
	while (i < size)
		ft_putendl(env[i++]);
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

int		check_builtin(t_file *s_file)
{
	int i;
	char *tmp;
	char *tmp2;
	
	i = 0;
	tmp = NULL;
	if (ft_strncmp(s_file->comm[0], "exit", 4) == 0)
	{
		ft_putendl("OKOK");
		free_struct(s_file);
	}
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
