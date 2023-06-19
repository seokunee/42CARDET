# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#              #
#    Updated: 2023/06/19 15:12:36 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.cpp Harl.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = harl

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
