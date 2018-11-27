/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 03:55:04 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 04:30:07 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char	**modify_value(char **tab, int pos, char *value)
{
	char **new;

	new = NULL;
	ft_putstr("Find");
	return (new);
}

void    do_set_env(t_file *s_file)
{
    int i;
    int find;
    char *tmp;
    char **new_env;
	char **search;
	
    i = 0;
    find = 0;
    tmp = NULL;
    while (i < s_file->size_env)
    {
		search = ft_strsplit(s_file->comm[1], '=');
		if (ft_strncmp(search[0], s_file->env[i], ft_strlen(search[0])) == 0)
		{
			find = i;
			search = free_split(search);
			break ;
		}
		search = free_split(search);
		i++;
	}
    if (find > 0)
    {
		free(s_file->env[find]);
		s_file->env[find] = ft_strdup(s_file->comm[1]);
		return ;
    }
    else
    {
    	if (!(tmp = ft_strdup(s_file->comm[1])))
            return ;
        new_env = add_in_tab(s_file->env, s_file->size_env, tmp);
    	free_env(s_file);
        s_file->env = new_env;
    	s_file->size_env++;
        free(tmp);
    }
}

void    put_env(char **env, int size)
{
    int i;

    i = 0;
    while (i < size)
        ft_putendl(env[i++]);
}
