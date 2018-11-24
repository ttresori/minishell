/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:03:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/24 03:43:35 by ttresori         ###   ########.fr       */
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
		
	i = 0;
	while (ft_strncmp(s_file->env[i], "PATH=", 5) != 0)
		i++;
	s_file->path = ft_strsplit(s_file->env[i], ':');
}

void    cpy_env(t_file *s_file, char **env)
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

t_file		*split_line(t_file *s_file, char *line)
{
	int 	i;
	int		pos;
	int		save;
	char	**split;
	
	i = 0;
	pos = 0;
	save = 0;
	if (!(split = ft_strsplit(line, ' ')))
		return (s_file);
	if (!(s_file->comm = ft_strdup(split[0])))
		return (s_file);
	s_file->size_comm = 1;
	pos = 1;
	i = pos;
	save = i;
	pos = 0;
	while (split[i] != NULL)
		if (split[i++][0] == '-')
			pos++;
	i = 0;
	if (pos > 0)
	{
		if (!(s_file->opt = (char**)malloc(sizeof(char*) * pos + 1)))
			return (s_file);
		s_file->opt[pos + 1] = NULL;
		s_file->size_opt = pos;
		while (split[save] != NULL)
		{
			if (split[save][0] == '-')
				s_file->opt[i++] = ft_strdup(split[save]);
			save++;
		}
//		s_file->arg = ft_strsplit(split[save - 1], ' ');
	}
	s_file->arg = ft_strsplit(s_file->comm, ' ');
	free_split(split);
	return (s_file);
}
