/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achavy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 23:37:46 by achavy            #+#    #+#             */
/*   Updated: 2018/12/17 06:02:27 by achavy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINISHELL_H
# define LIB_MINISHELL_H

# include "../libft/libft.h"
# include <sys/wait.h>

typedef struct	s_file
{
	char		**env;
	char		*pwd;
	char		*old_pwd;
	char		*home;
	int			size_env;
	char		**comm;
	int			size_comm;
	char		**path;
	int			size_path;
}				t_file;

int				place_home(t_file *s_file, int i);
int				split_line(t_file *s_file, char *line);
char			**free_split(char **split);
int				get_home(t_file *s_file);
void			print_prompt(void);
void			check_command(t_file *s_file);
void			free_line(t_file *s_file);
void			free_struct(t_file *s_file);
int				cpy_env(t_file *s_file, char **env);
void			put_env(char **env, int size);
void			put_path(t_file *s_file);
void			do_echo(t_file *s_file);
void			free_env(t_file *s_file);
void			do_set_env(t_file *s_file);
void			unset_env(t_file *s_file);
void			do_cd(t_file *s_file);
void			print_error_no_var_env(char *error);
void			add_env(t_file *s_file, char *var, char *element);
int				get_path(t_file *s_file);
int				check_if_dollar(t_file *s_file);
int				check_builtin(t_file *s_file);
int				check_own_builtin(t_file *s_file);

#endif
