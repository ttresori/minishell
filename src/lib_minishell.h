/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:56:31 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/28 16:28:25 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINISHELL_H
# define LIB_MINISHELL_H

# include "../libft/libft.h"

typedef struct	s_file
{
	char		**env;
	char		*pwd;
	char		*old_pwd;
	int			size_env;
	char		**comm;
	int			size_comm;
	char		**path;
	int			size_path;
}				t_file;

t_file			*split_line(t_file *s_file, char *line);
void			print_prompt(t_file *s_file);
void			check_command(t_file *s_file);
void			free_line(t_file *s_file);
void			free_struct(t_file *s_file);
void			cpy_env(t_file *s_file, char **env);
char			**free_split(char **split);
void			put_env(char **env, int size);
void			put_path(t_file *s_file);
void			do_echo(t_file *s_file);
void			free_env(t_file *s_file);
void			do_set_env(t_file *s_file);
void			unset_env(t_file *s_file);
void			do_cd(t_file *s_file);
void			print_error_no_var_env(char *error);
void 		    add_env(t_file *s_file, char *var, char *element);
void			get_path(t_file *s_file);
int				check_builtin(t_file *s_file);
int				search_env(char **env, int size, char *element);
int				check_own_builtin(t_file *s_file);

#endif
