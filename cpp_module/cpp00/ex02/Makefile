# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 22:07:00 by seokchoi          #+#    #+#              #
#    Updated: 2023/06/19 15:12:36 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS    = Account.cpp tests.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = account

all:		${NAME}

.cpp.o:		${SRCS}
			${CC} ${CXXFLAGS} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
