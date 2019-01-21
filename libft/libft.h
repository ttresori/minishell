/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:33:56 by ttresori          #+#    #+#             */
/*   Updated: 2018/12/01 14:20:00 by ttresori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include "get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include "get_next_line.h"
# define IS_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x  == '\f')
# define BLACK	"\033[1;30m"
# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define YELLOW	"\033[1;33m"
# define BLUE	"\033[1;34m"
# define PURPLE	"\033[1;35m"
# define CYAN	"\033[1;36m"
# define GREY	"\033[1;37m"
# define NORMAL	"\033[0m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
void				ft_putstr(const char *str);
void				ft_putstrspace(const char *str);
void				ft_putstrstart(char *str, int start);
void				ft_puttab(const char *str);
void				ft_putntab(const char *str, size_t stop);
void				ft_startstop(const char *str, size_t start, size_t stop);
void				ft_putnbr(int nb);
void				ft_putnbrtab(int n);
void				ft_putnbrspace(int n);
void				ft_print_space(int i);
void				ft_putendl(const char *s);
void				ft_putendl_b(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_bzero(void *s, size_t n);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
char				**ft_char_2d(int it, int jt);
char				**remove_in_tab(char **tab, int size, int pos);
void				ft_free_char_2d(char **tab);
void				ft_free_char_3d(char ***tab);
void				ft_free_int_2d(int **tab, int il);
void				ft_free_int_3d(int ***tab, int il, int jl);
void				*ft_realloc(void *ptr, size_t prev_size, size_t new_size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_startcpy(char *dest, const char *src, int start);
char				*ft_strncpy(char *dest, const char *src, size_t len);
char				*ft_strstr(const char *m, const char *n);
char				*ft_strnstr(const char *m, const char *n, size_t len);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t len);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strdup(const char *src);
char				*ft_strsdup(const char *src, int start, int stop);
char				*ft_strndup(const char *src, size_t lenght);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strjoinca(const char *s1, const char *s2, char c);
char				*ft_strtrim(const char *s);
char				*ft_itoa(int n);
char				**ft_strsplit(const char *s, char c);
char				*ft_strjoincl(char *s1, char *s2, int free_both);
char				*ft_strjoinchcl(char *s1, char c);
char				*ft_strjoinch(char const *s1, char c);
char				**add_in_tab(char **tab, int size, char *element);
char				**ft_strsplit_set(char const *s, char const *delims);
char				**free_split(char **split);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
int					ft_isascii(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isdigit(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_get_next_line(int fd, const char **line);
int					ft_atoi(const char *str);
int					search_env(char **env, int size, char *element);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
int					print_tab(char **tab);
int					get_next_line(int fd, char **line);

#endif
