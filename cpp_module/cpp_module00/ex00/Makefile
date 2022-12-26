# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#              #
#    Updated: 2022/12/26 02:07:48 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = megaphone.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = megaphone

all:		${NAME}

.cpp.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.cpp=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}
			
clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean ree
