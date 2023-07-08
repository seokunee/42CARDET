# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 18:36:16 by seokchoi          #+#    #+#              #
#    Updated: 2023/07/08 14:52:00 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.cpp Fixed.cpp
OBJS	= ${SRCS:.cpp=.o}
CXX		= c++
CXXFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = fix

all:		${NAME}

.cpp.o:		${SRCS}
			${CXX} ${CXXFLAGS} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CXX) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
