# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttresori <ttresori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/22 21:43:02 by carmand           #+#    #+#              #
#    Updated: 2018/11/27 04:00:03 by ttresori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCDIR = src
SRC = main.c utils.c save.c free.c builtin.c env.c

OBJDIR = obj
OBJ = $(SRC:.c=.o)

LIBDIR = libft
LIB = ft

CFLAGS = -Wall -Wextra -g

all: $(LIBDIR)/lib$(LIB).a $(OBJDIR) $(NAME)

$(LIBDIR)/lib$(LIB).a:
	@tput setaf 90 ; echo [COMPILE]
	@make -C $(LIBDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	@$(CC) $(CFLAGS) $(addprefix $(OBJDIR)/, $(OBJ)) -o $(NAME) -L $(LIBDIR) -l $(LIB)
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

tmpc:
	@tput setaf 90 ; echo [Delete temporary file]
	@rm -rf *~
	@rm -rf src/*~

re: fclean all

.PHONY: re fclean clean all
