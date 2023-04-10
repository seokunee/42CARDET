# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:56:05 by seokchoi          #+#    #+#              #
#    Updated: 2023/04/10 19:27:44 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.cpp ScalarConverter.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = convert

all:		${NAME}

.cpp.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
