# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/07/17 16:55:55 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = pipex.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = pipex
HEAD	= includes
LIBFT	= libft

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			make all -C ${LIBFT}/ 
			$(CC) -I $(HEAD) -o $(NAME) ${OBJS} -L ./libft -lft
			
clean:
			make clean -C ${LIBFT}/
			rm -f ${OBJS}

fclean:		clean
			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re