# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:56:05 by seokchoi          #+#    #+#              #
#    Updated: 2023/06/19 15:12:36 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = fragTrap

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
