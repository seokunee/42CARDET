/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/28 20:47:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_data *data, int *flag)
{
	int	i;
	time_t	elapsed_time;

	i = -1;
	while (++i < data->set_up.num_philos)
	{
		if (get_cur_time() - data->philos[i]->last_eat_time > data->set_up.time_to_die)
		{
			*flag = 0;
			elapsed_time = get_cur_time() - data->philos[i]->data->set_up.start_time;
			printf("%ld %d died\n", elapsed_time, data->philos[i]->id);
			break ;
		}
	}
}

void	check_done_all(t_data *data, int *flag)
{
	int	i;

	i = -1;
	if (data->set_up.num_must_eat != -1)
	{
		while (++i < data->set_up.num_philos)
		{
			if (data->done_check_box[i] == 0)
				break ;
			if (i == data->set_up.num_philos - 1)
				*flag = 0;
		}
	}
}

int	watch_threads(t_data *data)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		check_die(data, &flag);
		check_done_all(data, &flag);
	}
	return (0);
}

void	test_check_done(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data			data;

	set_philo_data(&data, ac, av);
	iterate_pthread_create(&data);
	iterate_pthread_detach(&data);
	watch_threads(&data);
	
	return (0);
}
