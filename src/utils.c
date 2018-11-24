/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:18:52 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/24 03:33:39 by ttresori         ###   ########.fr       */
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

void	check_command(t_file *s_file)
{
	pid_t father;

	char	*new_arg[] = {"-la", "../",  NULL};
	
	if (ft_strncmp(s_file->comm, "exit", 4) == 0)
		free_struct(s_file);
	if (ft_strncmp(s_file->comm, "env", 3) == 0)
		put_env(s_file->env, s_file->size_env);
	if (ft_strncmp(s_file->comm, "ls", 2) == 0)
	{
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			execve("/bin/ls", new_arg, s_file->env);
			ft_putstr_fd("minishell: command not found: ", 2);
			exit(0);
		}
	}
}
