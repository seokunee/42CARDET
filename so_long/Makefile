# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/06/29 22:07:13 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = so_long.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = so_long
HEAD	= includes
LIBFT	= libft

all:		${NAME}
			
# all:
# 			arch -x86_64 gcc -L./mlx -lmlx -framework OpenGL -framework AppKit srcs/so_long.c
# 			./a.out
#			-Llibft -lft

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
#			arch -x86_64 make all -C ${LIBFT}/ -L./libft -lft
			arch -x86_64 $(CC) -o $(NAME) $(OBJS) -L./mlx -lmlx -framework OpenGL -framework AppKit 
			
clean:
			make clean -C ${LIBFT}/
			rm -f ${OBJS}

fclean:		clean
			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re