# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 18:31:19 by seokchoi          #+#    #+#              #
#    Updated: 2022/10/17 19:24:36 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = so_long.c get_next_line.c image.c map.c so_long_ft.c element.c move.c
SOURCE	= srcs/
OBJS	= ${addprefix ${SOURCE},${SRCS:.c=.o}}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
NAME    = so_long
HEAD	= includes
LIBFT	= libft
MLX_DIR = mlx

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -I ${HEAD} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			make -C ${LIBFT}/ 
			make -C $(MLX_DIR)
			$(CC) -I $(HEAD) -o $(NAME) ${OBJS} -L ./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit 

clean:
			make clean -C ${LIBFT}/
			make clean -C $(MLX_DIR)/
			rm -f ${OBJS}

fclean:		clean
			make fclean -C ${LIBFT}/
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re