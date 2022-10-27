/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/27 21:58:29 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all_mutexs(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		pthread_mutex_destroy(&data->mutexs[i]);
		i++;
	}
}

int	watch_threads(t_data *data)
{
	int	i;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = -1;
		while (i++ < data->set_up.num_philos)
		{
			if (data->philos[i]->last_eat_time - get_cur_time() > data->set_up.time_to_die)
				flag = 0;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data			data;

	set_philo_data(&data, ac, av);
	iterate_pthread_create(&data);
	iterate_pthread_detach(&data);
	watch_threads(&data);
	write(1, "finish\n", 7);
	free_all_mutexs(&data);
	return (0);
}
