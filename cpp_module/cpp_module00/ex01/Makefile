# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 18:34:31 by seokchoi          #+#    #+#              #
#    Updated: 2022/12/30 12:48:56 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = PhoneBook.cpp Contact.cpp main.cpp
OBJS	= ${SRCS:.cpp=.o}
CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
NAME    = PhoneBook

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

.PHONY:		all clean fclean ree
