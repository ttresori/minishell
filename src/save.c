/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:03:02 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/21 04:07:41 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

int		cut_path(t_file *s_file, char *path)
{
	static 	int 	i = 5;
	static 	int		i2 = 0;
	int		i3 = 0;
	
	char 	*tmp;
	
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(path))))
		return (-1);
	while (path[i])
	{
		if (path[i] == ':')
		{
			tmp[i3] = '\0';
			if (!(s_file->path[i2] = ft_strndup(tmp, i3)))
				return (-1);
			i++;
			i2++;
			free(tmp);
			return (0);
		}
		tmp[i3] = path[i];
		i++;
		i3++;
	}
//	i2++;
	free(tmp);
	if (i2 == s_file->size_path)
		return (1);
	return (0);
}

void	put_path(t_file *s_file)
{
	int i;

	i = 0;
	while (i < s_file->size_path)
	{
		ft_putendl(s_file->path[i]);
		i++;
	}
}

void	get_path(t_file *s_file)
{
	int		i;
	int		nb_to_cut;
	char	*path;

	i = 0;
	nb_to_cut = 0;
	s_file->size_path = 0;
	while (ft_strncmp(s_file->env[i], "PATH=", 5) != 0)
		i++;
	if (!(path = ft_strdup(s_file->env[i])))
		return ;
	while (path[i])
	{
		if (path[i] == ':')
			nb_to_cut++;
		i++;
	}
	s_file->size_path = nb_to_cut + 1;
	if (!(s_file->path = (char**)malloc(sizeof(char) * s_file->size_path)))
		return ;	
	while (cut_path(s_file, path) != 1);
	put_path(s_file);
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
	int		comm;
	int 	opt;
	int 	arg;
	char	**split;
	
	i = 0;
	comm = 0;
	opt = 0;
	arg = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != '\0')
		i++;
	if (i >= 1)
	{
		s_file->comm = ft_strdup(split[0]);
		s_file->size_comm = 1;
		comm = 1;
	}
	if (i >= 2)
	{
		s_file->opt = ft_strdup(split[1]);
		s_file->size_opt = 1;
		opt = 1;
	}
	if (i >= 3)
	{
		s_file->arg = ft_strdup(split[2]);
		s_file->size_arg = 1;
		arg = 1;
	}
	free_split(split);
	return (s_file);
}
