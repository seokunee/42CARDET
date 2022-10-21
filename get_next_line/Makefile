# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 16:21:54 by seokchoi          #+#    #+#              #
#    Updated: 2022/10/21 16:08:23 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
MAIN = main_bonus.c
CC = cc
CFLAGS	= -Wall -Wextra -Werror
ifdef !BUF
	BUF = 42
endif

all : 
		${CC} ${CFLAGS} -D BUF=${BUF} ${SRC} ${MAIN}
		./a.out	example/test2 | cat -e
		
norm :
		norminette  -R CheckForbiddenSourceHeader ${SRC} ${BONUS_SRC}
norh :
		norminette  -R CheckDefine get_next_line.h get_next_line_bonus.h

.PHONY : all norm