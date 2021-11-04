# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 14:00:28 by ugdaniel          #+#    #+#              #
#    Updated: 2021/11/04 13:46:02 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[31m
GREEN = \033[32m
BLUE = \033[34m
WHITE = \033[39m
RESET = \033[0m

CC = clang

CFLAGS = -Wall -Wextra -Werror -g

INC = -Iincludes/ \
	-Ilibft/ \

LIBS = -Llibft -lft

SERVER = server
SRCS_SERVER = ./srcs/server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CLIENT = client
SRCS_CLIENT = ./srcs/client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

SERVER_BONUS = server_bonus
SRCS_SERVER_BONUS = ./srcs/bonus/server_bonus.c
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)

CLIENT_BONUS = client_bonus
SRCS_CLIENT_BONUS = ./srcs/bonus/client_bonus.c
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)

LIBFT = libft.a

all: $(CLIENT) $(SERVER)
	@echo "$(GREEN)Minitalk ready!"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(GREEN)Minitalk bonus ready!"

.c.o:
	$(CC) $(CFLAGS) $(INC) -c $< -o $@


$(CLIENT): $(OBJS_CLIENT)
	@echo "Minitalk creating $@ ..."
	@$(MAKE) -sC libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "$(BLUE)Client ready.$(RESET)"

$(SERVER): $(OBJS_SERVER)
	@echo "Minitalk creating $@ ..."
	@$(MAKE) -sC libft
	$(CC) $(CFLAGS) -o $@ $(OBJS_CLIENT) $(LIBS)
	@echo "$(BLUE)Server ready.$(RESET)"

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@echo "Minitalk creating $@ ..."
	@$(MAKE) -sC libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "$(BLUE)Client bonus ready.$(RESET)"

$(SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@echo "Minitalk creating $@ ..."
	@$(MAKE) -sC libft
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "$(BLUE)Server bonus ready.$(RESET)"

clean:
	@$(MAKE) -sC libft clean
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: 
	@$(MAKE) -sC libft fclean
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

norme:
	@norminette ./libft ./includes ./srcs

.PHONY: all clean fclean re
