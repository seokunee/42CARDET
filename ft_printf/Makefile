# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/10/17 19:23:47 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_printf.c flag_c.c flag_s.c flag_di.c flag_p.c flag_u.c flag_x.c flag_xx.c ft_strchar.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME    = libftprintf.a
HEAD	= includes

all :		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			ar -rcs $@ ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re