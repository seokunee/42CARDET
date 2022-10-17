# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/10/17 18:07:28 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME    = philo
LIBFT	= libft

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
#			make all -C ${LIBFT}/ s
			$(CC) -o $(NAME) ${OBJS} -L ./libft -lft

clean:
			make clean -C ${LIBFT}/
			rm -f ${OBJS}

fclean:		clean
#			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re