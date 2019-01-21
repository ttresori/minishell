/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 00:46:24 by achavy            #+#    #+#             */
/*   Updated: 2018/12/21 19:25:40 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	help_modify(t_file *s_file)
{
	int		pos;
	char	*tmp;
	char	buf[255];

	pos = -1;
	if (!(s_file->old_pwd = ft_strdup(s_file->pwd)))
		return ;
	pos = search_env(s_file->env, s_file->size_env, "PWD");
	if (pos > -1)
		free(s_file->env[pos]);
	else
	{
		add_env(s_file, "PWD=", s_file->pwd);
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

void	modify_in_env(t_file *s_file)
{
	int		pos;
	char	*tmp;

	pos = search_env(s_file->env, s_file->size_env, "OLDPWD");
	if (pos > -1)
		free(s_file->env[pos]);
	else
	{
		add_env(s_file, "OLDPWD=", s_file->old_pwd);
		return ;
	}
	if (!(tmp = ft_strjoin("OLDPWD=", s_file->pwd)))
		return ;
	if (!(s_file->env[pos] = ft_strdup(tmp)))
		return ;
	free(s_file->old_pwd);
	free(tmp);
	help_modify(s_file);
}

char	*help_do_cd(t_file *s_file)
{
	char	*path;

	if (s_file->comm[1] == NULL)
	{
		if (!(get_home(s_file)))
		{
			print_error_no_var_env("HOME");
			return (NULL);
		}
		return (ft_strdup(s_file->home));
	}
	else
	{
		if (!(path = ft_strdup(s_file->comm[1])))
			return (NULL);
	}
	return (path);
}

char	*cd_go_to_home(t_file *s_file, char *path)
{
	char	**tmp;
	int		pos;

	pos = -1;
	free(path);
	pos = search_env(s_file->env, s_file->size_env, "HOME");
	if (pos == -1 && s_file->home == NULL)
	{
		print_error_no_var_env("HOME");
		return (NULL);
	}
	if (pos == -1)
		return (ft_strdup(s_file->home));
	if (!(tmp = ft_strsplit(s_file->env[pos], '='))
	|| (!(path = ft_strdup(tmp[1]))))
		return (NULL);
	free_split(tmp);
	return (path);
}

void	do_cd(t_file *s_file)
{
	char	*path;

	path = NULL;
	if ((path = help_do_cd(s_file)) == NULL)
		return ;
	if (path[0] == '-' && path[1] == '-')
	{
		if (!(path = cd_go_to_home(s_file, path)))
			return ;
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
