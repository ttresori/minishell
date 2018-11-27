/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:03:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 04:41:24 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	put_path(t_file *s_file)
{
	while (*s_file->path != NULL)
		ft_putendl(*s_file->path++);
}

void	get_path(t_file *s_file)
{
	int		i;
	char	**tmp;

	i = 0;
	while (ft_strncmp(s_file->env[i], "PATH=", 5) != 0)
		i++;
	s_file->path = ft_strsplit(s_file->env[i], ':');
	tmp = ft_strsplit(s_file->path[0], '=');
	free(s_file->path[0]);
	s_file->path[0] = ft_strdup(tmp[1]);
	i = 0;
	while (tmp[i] != NULL)
		ft_strdel(&tmp[i++]);
	free(tmp);
}

void	cpy_env(t_file *s_file, char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
		i++;
	s_file->size_env = i;
	if (!(s_file->env = (char**)malloc(sizeof(char*) * i)))
		return ;
	i = 0;
	while (i < s_file->size_env)
	{
		if (!(s_file->env[i] = ft_strdup(env[i])))
			return ;
		i++;
	}
	get_path(s_file);
}

t_file	*split_line(t_file *s_file, char *line)
{
	s_file->comm = ft_strsplit(line, ' ');
	return (s_file);
}
