# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 16:21:54 by seokchoi          #+#    #+#              #
#    Updated: 2022/04/12 19:55:34 by seokchoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line_utils.c
BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c
MAIN = _main1.c
CC = gcc
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