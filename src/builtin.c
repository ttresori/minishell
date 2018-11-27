/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 01:51:19 by ttresori          #+#    #+#             */
/*   Updated: 2018/11/27 03:47:58 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_minishell.h"

void	do_echo(t_file *s_file)
{
	int i;

	i = 1;
	while (s_file->comm[i] != NULL)
	{
		ft_putstr(s_file->comm[i]);
		i++;
		ft_putchar(' ');
	}
	ft_putchar('\n');
}


char	**add_in_tab(char **tab, int size, char *element)
{
	int 	i;
	char 	**new;
	
	i = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(new[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(new[size] = ft_strdup(element)))
		return (NULL);
	return (new);
}

void	do_set_env(t_file *s_file)
{
	int i;
	int find;
	char *tmp;
	char **new_env;
	
	i = 0;
	find = 0;
	tmp = NULL;
/*	while (i < s_file->size_env)
		if (ft_strncmp(s_file->env[i++], s_file->comm[1],	\
					   ft_strlen(s_file->comm[1])) == 0)
					   find = 1;*/
/*	if (find == 1)
	modify_value
	else*/
	if (!(tmp = ft_strdup(s_file->comm[1])))
		return ;
	new_env = add_in_tab(s_file->env, s_file->size_env, tmp);
	free_env(s_file);
	s_file->env = new_env;
	s_file->size_env++;
	free(tmp);
}

void    put_env(char **env, int size)
{
    int i;

    i = 0;
    while (i < size)
        ft_putendl(env[i++]);
}
