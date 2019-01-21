#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttresori <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 03:30:35 by ttresori          #+#    #+#              #
#    Updated: 2019/01/21 03:30:36 by ttresori         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = minishell

SRCDIR = src
SRC = main.c utils.c save.c free.c builtin.c env.c get_value.c cd.c

OBJDIR = obj
OBJ = $(SRC:.c=.o)

LIBDIR = libft

CFLAGS = -Wall -Wextra -Werror

all: $(LIBDIR)/libft.a $(OBJDIR) $(NAME)

$(LIBDIR)/libft.a:
	@tput setaf 90 ; echo [COMPILE]
	@make -C $(LIBDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@$(CC) $(CFLAGS) $(addprefix $(OBJDIR)/, $(OBJ)) -o $(NAME) -L $(LIBDIR) -lft
	@tput setaf 90 ; echo [DONE]

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@tput setaf 25 ; echo $<

clean:
	@tput setaf 70 ; echo [CLEAN --] [$(OBJDIR)] [$(LIBDIR)]
	@rm -rf $(OBJDIR)
	@make clean -C $(LIBDIR)

fclean: clean
	@tput setaf 70 ; echo [FCLEAN --] [$(NAME)] [$(LIBDIR)]
	@rm -rf $(NAME)
	@make fclean -C $(LIBDIR)

re: fclean all

.PHONY: re fclean clean all
