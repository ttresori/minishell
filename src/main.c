/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:56:08 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/24 03:43:37 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	core(char **env)
{
	char	*line;
	t_file	*s_file;
	
	ft_putstr("\033[H\033[2J");
	if (!(s_file = (t_file*)malloc(sizeof(t_file))))
		return ;
    s_file->size_comm = 0;
    s_file->size_opt = 0;
    s_file->size_arg = 0;
	s_file->opt = NULL;
	s_file->arg = NULL;
	s_file->comm = NULL;
	cpy_env(s_file, env);
	while (42)
	{
		print_prompt();
		get_next_line(0, &line);
		if (!(s_file = split_line(s_file, line)))
			return ;
		ft_strdel(&line);
		get_next_line(-2, NULL);
		//check_command(s_file);
		free_line(s_file);
	}
}

int		main(int argc, char **argv, char **env)
{
	if (env[0] == NULL)
	{
		ft_putendl_fd("No env", 2);
		return (0);
	}
	core(env);
	(void)argc;
	(void)argv;
	return (0);
}
