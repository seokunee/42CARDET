# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/06/24 18:47:14 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = so_long.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = so_long
HEAD	= includes

all :		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re