/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:56:08 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/17 03:42:06 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	core(char **env)
{
	char	*line;
	char	buf[256];
	t_file	s_file;

	s_file.size_comm = 0;
	s_file.comm = NULL;
	s_file.home = NULL;
	if (!(s_file.pwd = ft_strdup(getcwd(buf, 256)))
	|| !(s_file.old_pwd = ft_strdup(s_file.pwd))
	|| (!(cpy_env(&s_file, env))))
		return ;
	while (42)
	{
		print_prompt();
		get_next_line(0, &line);
		if (!(split_line(&s_file, line)))
			return ;
		get_next_line(-2, NULL);
		if (s_file.comm[0] != NULL)
			check_builtin(&s_file);
		ft_strdel(&line);
		free_line(&s_file);
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
	exit(0);
	return (0);
}
