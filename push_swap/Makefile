# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 21:14:22 by pdubois           #+#    #+#              #
#    Updated: 2022/01/28 01:21:38 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap
SRCS_NAME = main.c \
			free_utils.c \
			push_swap_utils1.c \
			push_swap_utils2.c \
			stack_utils1.c \
			stack_utils2.c \
			stack_utils3.c \
			stack_utils4.c \
			algo.c \
			algo_utils1.c \
			algo_utils2.c
SRCS_PATH = srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))
INC_NAME = push_swap.h
INC_PATH = includes
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
RM = rm -rf
OBJS = $(SRCS:.c=.o)
LIBS = libft/libft.a

all: $(NAME)

%.o : %.c
			${CC} ${CFLAGS} -I ${INC_PATH} -c $< -o $@

${LIBS}:
			cd libft; make

${NAME}:	${OBJS} ${INC} ${LIBS}
			${CC} -o ${NAME} ${OBJS} ${LIBS}
clean:
			${RM} ${OBJS}; cd libft; make clean

fclean:		clean
			${RM} ${NAME}; cd libft; make fclean

re:			fclean all

.PHONY : all clean fclean re
