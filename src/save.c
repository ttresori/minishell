/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:03:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 13:59:51 by ttresori         ###   ########.fr       */
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
	if (!(s_file->path = ft_strsplit(s_file->env[i], ':')))
		return ;
	if (!(tmp = ft_strsplit(s_file->path[0], '=')))
		return ;
	free(s_file->path[0]);
	if (!(s_file->path[0] = ft_strdup(tmp[1])))
		return ;
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

void	check_if_dollar(t_file *s_file)
{
	static 	int		i = 0;
	int		i2;
	int		pos;
	char	**tmp;
	char	**tmp2;

	i = 0;
	i2 = 0;
	pos = -1;
	while (i < s_file->size_comm)
	{
		if (s_file->comm[i][0] == '$' && s_file->comm[i][1] != '$')
		{
			if (!(tmp = ft_strsplit(s_file->comm[i], '$')))
				return ;
			pos = search_env(s_file->env, s_file->size_env, tmp[0]);
			if (pos == -1)
			{
				free_split(tmp);
				i++;
				check_if_dollar(s_file);
			}
			if (!(tmp2 = ft_strsplit(s_file->env[pos], '=')))
				return ;
			free(s_file->comm[i]);
			if (!(s_file->comm[i] = ft_strdup(tmp2[1])))
				return ;
			free_split(tmp);
			free_split(tmp2);
		}
		i++;
	}
	i = 0;
	return ;
}

t_file	*split_line(t_file *s_file, char *line)
{
	s_file->size_comm = 0;
	s_file->size_path = 0;
	s_file->comm = ft_strsplit(line, ' ');
	while (s_file->comm[s_file->size_comm] != NULL)
		s_file->size_comm++;
	while (s_file->path[s_file->size_path] != NULL)
		++s_file->size_path;
	check_if_dollar(s_file);
	return (s_file);
}
