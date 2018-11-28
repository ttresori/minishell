/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:15:17 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 18:21:38 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

char    *get_home(t_file *s_file)
{
    char **tmp;
    char *returnt;

    tmp = NULL;
    tmp = ft_strsplit(s_file->env[search_env(s_file->env, \
											 s_file->size_env, "HOME=")], '=');
    returnt = ft_strdup(tmp[1]);
    free_split(tmp);
    return (returnt);
}

void    get_path(t_file *s_file)
{
    int     i;
    char    **tmp;

    i = search_env(s_file->env, s_file->size_env, "PATH=");
    if (i < 0)
    {
        s_file->path = NULL;
        return ;
    }
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
    i = 0;
    while (s_file->path[i])
        i++;
    s_file->size_path = i + 1;
    free(tmp);
}
