# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdubois <pdubois@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/15 04:26:20 by pdubois           #+#    #+#              #
#    Updated: 2022/11/18 17:50:16 by pdubois          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = a.out

RM = rm -rf

SRCS_NAME =	main.cpp \
			AMateria.cpp \
			Ice.cpp \
			Cure.cpp \
			Character.cpp \
			MateriaSource.cpp
SRCS_PATH =	srcs
SRCS = $(addprefix $(SRCS_PATH)/, $(SRCS_NAME))

INCS_NAME =	AMateria.hpp \
			Ice.hpp \
			Cure.hpp \
			ICharacter.hpp \
			Character.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp
INCS_PATH = includes
INCS = $(addprefix $(INCS_PATH)/, $(INCS_NAME))

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

%.o : %.cpp ${INCS}
			${CC} ${CFLAGS} -I ${INCS_PATH} -c $< -o $@

${NAME}:	${OBJS} ${INCS}
			${CC} -o ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY : all clean fclean re