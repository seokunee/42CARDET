# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/06/30 21:20:14 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = so_long.c get_next_line.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
ADDSRCS = ${addprefix ${SOURCE},${SRCS}}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
NAME    = so_long
HEAD	= includes
LIBFT	= libft
MLX_DIR = mlx

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			arch -x86_64 make all -C ${LIBFT}/ 
#			arch -x86_64 make -C $(MLX_DIR)
			arch -x86_64 $(CC) -I $(HEAD) -o $(NAME) ${ADDSRCS} -L ./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit 
			
clean:
			make clean -C ${LIBFT}/
#			make clean -C $(MLX_DIR)/
			rm -f ${OBJS}

fclean:		clean
			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re