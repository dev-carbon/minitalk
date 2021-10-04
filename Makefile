# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 14:00:28 by ugdaniel          #+#    #+#              #
#    Updated: 2021/10/04 22:53:42 by humanfou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

red			= \033[91m
green 		= \033[92m
white 		= \033[39m
blue		= \033[94m
cyan 		= \033[96m
gray		= \033[37m
yellow		= \033[33m
magenta		= \033[35m

CC = clang

CFLAGS = -Wall -Wextra -Werror

INC = 	-Iincludes/ \
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

all: $(CLIENT) $(SERVER)
	@echo "$(green)Minitalk ready!"
	@echo "$(white)\c"

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(green)Minitalk bonus ready!"
	@echo "$(white)\c"

.c.o:
	# @echo "Creating object files directory"
	# @mkdir objs
	@echo "$(gray)Compiling $<... \c"
	@echo "$(red)\c"
	$(CC) $(CFLAGS) -g $(INC) -c $< -o $@
	@echo "$(cyan)OK!"

$(CLIENT): $(OBJS_CLIENT)
	@echo "$(yellow)Client: source files compiled."
	@echo "$(red)\c"
	$(CC) $(CFLAGS) -g -o $(CLIENT) $(OBJS_CLIENT) $(LIBS)
	@echo "$(blue)Client ready!"
	@echo "$(white)\c"

$(SERVER): $(OBJS_SERVER)
	@echo "$(yellow)Server: source files compiled."
	@echo "$(red)\c"
	$(CC) $(CFLAGS) -g -o $(SERVER) $(OBJS_SERVER) $(LIBS)
	@echo "$(blue)Server ready!"
	@echo "$(white)\c"

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS)
	@echo "$(yellow)Client bonus: source files compiled."
	@echo "$(red)\c"
	$(CC) $(CFLAGS) -g -o $(CLIENT_BONUS) $(OBJS_CLIENT_BONUS) $(LIBS)
	@echo "$(blue)Client bonus ready!"
	@echo "$(white)\c"

$(SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@echo "$(yellow)Server bonus: source files compiled."
	@echo "$(red)\c"
	$(CC) $(CFLAGS) -g -o $(SERVER_BONUS) $(OBJS_SERVER_BONUS) $(LIBS)
	@echo "$(blue)Server bonus ready!"
	@echo "$(white)\c"

clean:
	@echo "$(gray)Cleaning object files."
	@echo "$(red)\c"
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)
	@echo "$(magenta)Executables removed."
	@echo "$(red)\c"

re: fclean all

norme:
	norminette ./libft ./includes ./srcs

.PHONY: all clean fclean re
