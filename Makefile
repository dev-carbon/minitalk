# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 14:00:28 by ugdaniel          #+#    #+#              #
#    Updated: 2021/06/22 16:22:33 by ugdaniel         ###   ########.fr        #
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

SANITIZE = -fsanitize=address

INC = 	-Iincludes/ \
		-Ilibft/ \

LIBS = -Llibft -lft

SERVER = server
SRCS_SERVER = ./srcs/server.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

CLIENT = client
SRCS_CLIENT = ./srcs/client.c
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

OBJS_DIR = objs

all: $(CLIENT) $(SERVER)
	@echo "$(green)Minitalk ready!"
	@echo "$(white)\c"

.c.o:
	# @echo "Creating object files directory"
	# @mkdir objs
	@echo "$(gray)Compiling $<... \c"
	@echo "$(red)\c"
	$(CC) $(FLAGS) $(INC) -c $< -o $@
	@echo "$(cyan)OK!"

$(CLIENT): $(OBJS_CLIENT)
	@echo "$(yellow)Client: source files compiled."
	@echo "$(red)\c"
	$(CC) $(FLAGS) $(SANITIZE)  -o $(CLIENT) $(OBJS_CLIENT) $(LIBS)
	@echo "$(blue)Client ready!"
	@echo "$(white)\c"

$(SERVER): $(OBJS_SERVER)
	@echo "$(yellow)Server: source files compiled."
	@echo "$(red)\c"
	$(CC) $(FLAGS) $(SANITIZE) -o $(SERVER) $(OBJS_SERVER) $(LIBS)
	@echo "$(blue)Server ready!"
	@echo "$(white)\c"

clean:
	@echo "$(gray)Cleaning object files."
	@echo "$(red)\c"
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: clean
	@rm -f $(CLIENT) $(SERVER)
	@echo "$(magenta)Server executable removed."
	@echo "$(red)\c"

re: fclean all

.PHONY: all clean fclean re