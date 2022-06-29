/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:41:21 by seokchoi          #+#    #+#             */
/*   Updated: 2022/04/11 21:39:43 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(int ac, char **av)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	i;
	(void)ac;
	char *top;

	i = 0;
	fd1 = open("exmaple/test1", O_RDONLY);
	fd2 = open("exmaple/test2", O_RDONLY);
	fd3 = open("exmaple/test3", O_RDONLY);
	while (1)
	{
		top = get_next_line(fd1);
		if (top)
			printf("%s", top);
		else
			break ;
	}
	return (0);
}