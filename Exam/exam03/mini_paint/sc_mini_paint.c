/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_mini_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:25:30 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/23 20:53:27 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

typedef struct s_set
{
	int	wid;
	int	hei;
	char	back;
} 		t_set;

typedef struct s_oper
{
	char type;
	float X;
	float Y;
	float radius;
	char back;
}	t_oper;

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

char	*get_set_info(FILE *file, t_set *set)
{
	int		num;
	char	*tmp;
	int		i = 0;

	if ((num = fscanf(file,"%d %d %c\n", &set->wid, &set->hei, &set->back)) != 3)
		return (NULL);
	if (set->wid > 0 && set->wid <= 300 && set->hei > 0 && set->hei)
	{
		tmp = malloc(sizeof(char) * (set->wid * set->hei + 1));
		if (!tmp)
			return (NULL);
		while (i < set->wid * set->hei)
		{
			tmp[i] = set->back;
			i++;
		}
		tmp[i] = '\0';
		return (tmp); 
	}
	else
		return (NULL);
}

void	print_map(t_set *set, char *zone)
{
	int	i = 0;

	while (zone[i])
	{
		write(1, &zone[i], 1);
		if (i % set->wid == set->wid - 1)
			write(1, "\n", 1);
		i++;
	}
}

int	free_all(FILE *file, char *zone)
{
	if (file)
		fclose(file);
	if (zone)
		free(zone);
	return (1);
}

// line을 하나씩 보면서 원을 그려주는 
void	set_circle(FILE *file, char *zone, t_set *set)
{
	t_oper	oper;
	int		num;

	while (num = fscanf(file ,"%c %f %f %f %c\n", &oper.type, &oper.X, &oper.Y, &oper.radius, &oper.back) == 5)
	{
		if ()
		{
			
		}
	}
}

int	main(int ac, char **av)
{
	t_set set;
	FILE *file;
	char *zone;

	set.back = 0;
	set.hei = 0;
	set.wid = 0;
	if (ac != 2)
		return (throw_error("Error: argument\n"));
	file = fopen(av[1], "r");
	if (!file)
		return (throw_error("Error: Operation file corrupted\n"));
	if ((zone = get_set_info(file, &set)) == NULL) // 기본 zone 생성
	{
		free_all(file, zone);
		return (throw_error("Error: Operation file corrupted\n"));
	}
	// if (g)
	print_map(&set, zone);
	printf("\n%d %d %c\n", set.wid, set.hei, set.back);
	return (0);
}
