/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 23:37:59 by achavy            #+#    #+#             */
/*   Updated: 2018/12/17 06:21:10 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	put_path(t_file *s_file)
{
	while (*s_file->path != NULL)
		ft_putendl(*s_file->path++);
}

int		cpy_env(t_file *s_file, char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
		i++;
	s_file->size_env = i;
	if (!(s_file->env = (char**)malloc(sizeof(char*) * (i + 1))))
		return (0);
	i = 0;
	while (i < s_file->size_env)
	{
		if (!(s_file->env[i] = ft_strdup(env[i])))
			return (0);
		i++;
	}
	s_file->env[i] = NULL;
	if ((get_path(s_file)))
		return (1);
	return (0);
}

int		help_check_dollar(t_file *s_file, int *i)
{
	int				pos;
	char			**tmp;
	char			**tmp2;

	pos = -1;
	if (!(tmp = ft_strsplit(s_file->comm[*i], '$')))
		return (0);
	pos = search_env(s_file->env, s_file->size_env, tmp[0]);
	if (pos == -1)
	{
		free_split(tmp);
		if (!(s_file->comm = remove_in_tab(s_file->comm, s_file->size_comm, *i)))
			return (0);
		s_file->size_comm--;
		*i = *i - 1;
		return (1);
	}
	if (!(tmp2 = ft_strsplit(s_file->env[pos], '=')))
		return (0);
	free(s_file->comm[*i]);
	if (!(s_file->comm[*i] = ft_strdup(tmp2[1])))
		return (0);
	free_split(tmp);
	free_split(tmp2);
	return (1);
}

int		check_if_dollar(t_file *s_file)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < s_file->size_comm)
	{
		if (s_file->comm[i][0] == '$' && s_file->comm[i][1] != '$')
		{
			if (!(help_check_dollar(s_file, &i)))
				return (0);
		}
		else if ((tmp = ft_strchr(s_file->comm[i], '~')) && (tmp[1] != '~'))
		{
			if (!(place_home(s_file, i)))
				return (0);
		}
		i++;
	}
	return (1);
}

int		split_line(t_file *s_file, char *line)
{
	s_file->size_comm = 0;
	if (!(s_file->comm = ft_strsplit_set(line, " \t\r\f")))
		return (0);
	while (s_file->comm[s_file->size_comm] != NULL)
		s_file->size_comm++;
	if (!(check_if_dollar(s_file)))
		return (0);
	if (s_file->path != NULL)
		free_split(s_file->path);
	if (!(get_path(s_file)))
		return (0);
	return (1);
}
