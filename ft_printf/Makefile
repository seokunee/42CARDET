# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/04/19 18:03:51 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_printf.c	
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = libftprintf.a
HEAD	= includes

ifdef WITH_B
	OBJECTS = $(OBJS) $(OBJS_BONUS)
else
	OBJECTS = $(OBJS)
endif

all :		${NAME}

.c.o:		${SRCS} $(SRCS_BONUS)
			${CC} ${CFLAGS} -I ${HEAD} -c $^

${NAME}:	${OBJECTS}
			ar -rcs $@ ${OBJECTS}

bonus:
			@make WITH_B=1 all

clean:
			rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus