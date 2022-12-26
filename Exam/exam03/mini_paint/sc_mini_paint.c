/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc_mini_paint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:25:30 by seokchoi          #+#    #+#             */
/*   Updated: 2022/12/24 17:03:35 by seokchoi         ###   ########.fr       */
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

int	free_all(FILE *file, char *zone, char *error)
{
	if (file)
		fclose(file);
	if (zone)
		free(zone);
	if (error)
		throw_error("Error: Operation file corrupted\n");
	return (1);
}

// void	exec_C(int x, int y, t_set *set)
// {
	
// }

// void	exec_c()
// {
	
// }

// line을 하나씩 보면서 원을 그려주는 
int	set_circle(FILE *file, char *zone, t_set *set)
{
	t_oper	oper;
	int		num;
	int		i;
	int		x;
	int		y;

	i = 0;
	while ((num = fscanf(file ,"%c %f %f %f %c\n", &oper.type, &oper.X, &oper.Y, &oper.radius, &oper.back)) == 5)
	{
		i = 0;
		if (oper.radius <= 0.00000000 || (oper.type != 'c' && oper.type != 'C'))
			return (0);
		while (zone[i])
		{
			x = i % set->wid;
			y = i / set->wid;
			if (oper.type == 'c')
			{
				if (oper.radius >= sqrtf(powf(x - oper.X, 2) + powf(y - oper.Y, 2)) \
					&& oper.radius - 1.00000000 < sqrtf(powf(x - oper.X, 2) + powf(y - oper.Y, 2)))
					zone[i] = oper.back;
			}
			else if (oper.type == 'C')
			{
				if (oper.radius >= sqrtf(powf(x - oper.X, 2) + powf(y - oper.Y, 2)))
					zone[i] = oper.back;
			}
			i++;
		}
	}
	if (num != -1)
		return (0);
	return (1);
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
		return (free_all(file, zone, "Error: Operation file corrupted\n"));
	if (set_circle(file, zone, &set) == 0)
		return (free_all(file, zone, "Error: Operation file corrupted\n"));
	print_map(&set, zone);
	free_all(file, zone, NULL);
	return (0);
}
