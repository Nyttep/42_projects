# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 04:26:20 by pdubois           #+#    #+#              #
#    Updated: 2022/10/25 18:23:11 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = mySed

RM = rm -f

SRCS =	main.cpp \

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

%.o : %.cpp
			${CC} ${CFLAGS} -I ./ -c $< -o $@

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}
			@mkdir .objdir; mv *.o .objdir

clean:
			${RM} -rf .objdir

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re