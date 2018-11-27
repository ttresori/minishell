/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 05:42:58 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 06:14:39 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	modify_in_env(t_file *s_file)
{
	int pos;
	char *tmp;
	char buf[255];
	
	pos = search_env(s_file->env, s_file->size_env, "OLDPWD=");
	free(s_file->env[pos]);
	if (!(tmp = ft_strjoin("OLDPWD=", s_file->pwd)))
		return ;
	s_file->env[pos] = ft_strdup(tmp);
	free(s_file->old_pwd);
	free(tmp);
	pos = -1;
	if (!(s_file->old_pwd = ft_strdup(s_file->pwd)))
		return ;
	pos = search_env(s_file->env, s_file->size_env, "PWD=");
	free(s_file->env[pos]);
	free(s_file->pwd);
	if (!(s_file->pwd = ft_strdup(getcwd(buf, 255))))
        return ;
	if (!(tmp = ft_strjoin("PWD=", s_file->pwd)))
		return ;
	s_file->env[pos] = ft_strdup(tmp);
	free(tmp);
}

void	do_cd(t_file *s_file)
{
	char	*path;
	char	*tmp;
	char	*tmp2;
	
	path = ft_strdup(s_file->comm[1]);
	if (s_file->comm[1] == NULL)
		return ;
	if (path[0] == '-')
	{
		free(path);
		path = ft_strdup(s_file->old_pwd);
	}
	if (chdir(path) == 0)
		modify_in_env(s_file);
	free(path);
}
