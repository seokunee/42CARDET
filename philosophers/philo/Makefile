# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/11/02 16:51:08 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = main.c error.c ft_atoi.c ft_putstr_fd.c set_data.c \
			malloc_data.c iter_pthread.c philo_to_do.c ft_calloc.c \
			watch.c to_do.c set_up.c sleep.c time.c
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3 -fsanitize=thread
NAME    = philo
LIBFT	= libft

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re