/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_minishell.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <rammsteinluffy@gmail.co...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:56:31 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 01:26:25 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MINISHELL_H
# define LIB_MINISHELL_H

# include "../libft/libft.h"

typedef struct	s_file
{
	char		**env;
	int			size_env;
	char		**comm;
	int			size_comm;
	char		**path;
	int			size_path;
}				t_file;

t_file			*split_line(t_file *s_file, char *line);
void			print_prompt();
void			check_command(t_file *s_file);
void			free_line(t_file *s_file);
void			free_struct(t_file *s_file);
void			cpy_env(t_file *s_file, char **env);
void			free_split(char **split);
void			put_env(char **env, int size);
void			put_path(t_file *s_file);
int				check_builtin(t_file *s_file);

#endif
