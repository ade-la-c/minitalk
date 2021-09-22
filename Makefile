# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 14:45:52 by ade-la-c          #+#    #+#              #
#    Updated: 2021/09/22 13:32:48 by ade-la-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER				= server

CLIENT				= client

SRCS				= srcs/client/client.c \
					srcs/server/server.c \

OBJS				= $(SRCS:.c=.o)

CC					= gcc

RM					= rm -f

CFLAGS				= -Wall -Werror -Wextra -I. #-g -fsanitize=address

LIB					= -L ./libft -lft

CL_GREY				= \033[38;2;128;128;128m

CL_GREEN			= \033[38;2;0;153;0m

CL_RESET			= \033[0m

.c.o:
					@${CC} ${CFLAGS} -c $^ -o $@

all:				$(SERVER) $(CLIENT)

$(SERVER):	$(OBJS)
					@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
					@echo "$(CL_GREY)"
					@$(MAKE) -C ./libft bonus
					@echo "$(CL_RESET)"
					@echo "$(CL_GREEN)-> COMPILING MINITALK SERVER$(CL_RESET)"
					@echo "$(CL_GREY)"
					$(CC) ${CFLAGS} -o$(SERVER) $(OBJS) $(LIB)
					@echo "$(CL_RESET)"

$(CLIENT):	$(OBJS)
					@echo "$(CL_GREEN)-> COMPILING LIBFT$(CL_RESET)"
					@echo "$(CL_GREY)"
					@$(MAKE) -C ./libft bonus
					@echo "$(CL_RESET)"
					@echo "$(CL_GREEN)-> COMPILING MINITALK CLIENT$(CL_RESET)"
					@echo "$(CL_GREY)"
					$(CC) ${CFLAGS} -o$(CLIENT) $(OBJS) $(LIB)
					@echo "$(CL_RESET)"

clean:
					@echo "$(CL_GREEN)-> CLEAN$(CL_RESET)"
					@echo "$(CL_GREY)"
					@$(MAKE) -C ./libft clean
					$(RM) $(OBJS) $(BOBJS)
					@echo "$(CL_RESET)"

fclean:			clean
					@echo "$(CL_GREEN)-> FCLEAN$(CL_RESET)"
					@echo "$(CL_GREY)"
					@$(MAKE) -C ./libft fclean
					$(RM) $(NAME) $(BNAME)
					@echo "$(CL_RESET)"

re:				fclean all

mclean:			all clean

.PHONY:			all clean fclean re