/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_mini_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:25:30 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/23 16:27:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_set
{
	int	wid;
	int	hei;
	char	back;
} 		t_set;

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

int	throw_error(char *message)
{
	write(1, message, ft_strlen(message));
	return (1);
}

int	get_set_info(FILE *file, t_set *set)
{
	int	num;

	if ((num = fscanf(file,"%d %d %c", &set->wid, &set->hei, &set->back)) != 3)
		return (0);
	return (1);
}
int	main(int ac, char **av)
{
	t_set set;
	FILE *file;
	char *paint;

	set.back = 0;
	set.hei = 0;
	set.wid = 0;
	if (ac != 2)
		return (throw_error("Error: argument\n"));
	file = fopen(av[1], "r");
	if (!file)
		return (throw_error("Error: Operation file corrupted\n"));
	if (get_set_info(file, &set) == 0)
	{
		fclose(file);
		return (throw_error("Error: Operation file corrupted\n"));
	}
	printf("%d %d %c\n", set.wid, set.hei, set.back);
	return (0);
}