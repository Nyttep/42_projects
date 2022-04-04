# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 16:55:50 by pdubois           #+#    #+#              #
#    Updated: 2022/03/30 18:01:06 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME_SERVER = server
NAME_CLIENT = client
SRCS_NAME_CLIENT = client.c
SRCS_NAME_SERVER = server.c
SRCS_PATH = srcs
SRCS_SERVER = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME_SERVER))
SRCS_CLIENT = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME_CLIENT))
INCS_NAME = server.h \
			client.h
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))
LIBS = libft/libft.a
RM = rm -rf
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o : %.c
			${CC} ${CFLAGS} -g -I ${INCS_PATH} -I libft -c $< -o $@

${LIBS}:
			make -C libft

${NAME_SERVER}:	${OBJS_SERVER} ${INCS} ${LIBS}
			${CC} -g -o ${NAME_SERVER} ${OBJS_SERVER} ${LIBS}

${NAME_CLIENT}:	${OBJS_CLIENT} ${INCS} ${LIBS}
			${CC} -g -o ${NAME_CLIENT} ${OBJS_CLIENT} ${LIBS}

clean:
			${RM} ${OBJS_CLIENT} ${OBJS_SERVER}; make -C libft clean;

fclean:		clean
			${RM} ${NAME_SERVER} ${NAME_CLIENT}; make -C libft fclean;

re:			fclean all

.PHONY : all clean fclean re