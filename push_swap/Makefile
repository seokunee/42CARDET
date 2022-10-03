# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/10/03 17:55:10 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = push_swap.c parse.c parse1.c utility.c operation_s.c \
			operation_p.c  operation_r.c  operation_rr.c \
			sort.c a_to_b.c b_to_a.c hard_sort.c a_to_b_hard.c \
			b_to_a_hard.c
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = push_swap
LIBFT	= libft

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			make all -C ${LIBFT}/ 
			$(CC) -o $(NAME) ${OBJS} -L ./libft -lft

clean:
			make clean -C ${LIBFT}/
			rm -f ${OBJS}

fclean:		clean
			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re