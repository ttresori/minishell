/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 05:42:58 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 15:25:37 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	modify_in_env(t_file *s_file)
{
	int		pos;
	char	*tmp;
	char	buf[255];
	
	pos = search_env(s_file->env, s_file->size_env, "OLDPWD=");
	if (pos > -1)
		free(s_file->env[pos]);
	else
	{
		print_error_no_var_env("OLDPWD");
		return ;
	}
	if (!(tmp = ft_strjoin("OLDPWD=", s_file->pwd)))
		return ;
	if (!(s_file->env[pos] = ft_strdup(tmp)))
		return ;
	free(s_file->old_pwd);
	free(tmp);
	pos = -1;
	if (!(s_file->old_pwd = ft_strdup(s_file->pwd)))
		return ;
	pos = search_env(s_file->env, s_file->size_env, "PWD=");
	if (pos > -1)
		free(s_file->env[pos]);
	else
	{
		print_error_no_var_env("PWD");
		return ;
	}
	free(s_file->pwd);
	if (!(s_file->pwd = ft_strdup(getcwd(buf, 255))))
		return ;
	if (!(tmp = ft_strjoin("PWD=", s_file->pwd)))
		return ;
	if (!(s_file->env[pos] = ft_strdup(tmp)))
		return ;
	free(tmp);
}

void	do_cd(t_file *s_file)
{
	char	*path;
	char	**tmp;
	int		pos;

	pos = -1;
	if (s_file->comm[1] == NULL)
	{
		pos = search_env(s_file->env, s_file->size_env, "HOME");
		if (pos == -1)
		{
			print_error_no_var_env("HOME");
			return ;
		}
		if (!(tmp = ft_strsplit(s_file->env[pos], '=')))
			return ;
		if (!(path = ft_strdup(tmp[1])))
			return ;
		free_split(tmp);
	}
	else
		if (!(path = ft_strdup(s_file->comm[1])))
			return ;
	if (path[0] == '-' && path[1] == '-')
	{
		free(path);
		pos = search_env(s_file->env, s_file->size_env, "HOME");
		if (pos == -1)
		{
			print_error_no_var_env("HOME");
			return ;
		}
		if (!(tmp = ft_strsplit(s_file->env[pos], '=')))
			return ;
		if (!(path = ft_strdup(tmp[1])))
			return ;
		free_split(tmp);
	}
	else if (path[0] == '-' && path[1] == '\0')
	{
		free(path);
		if (!(path = ft_strdup(s_file->old_pwd)))
			return ;
	}
	if (chdir(path) == 0)
		modify_in_env(s_file);
	else
		ft_putendl_fd("Error cd", 0);
	free(path);
}
