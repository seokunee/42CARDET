/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/08 18:21:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mutex_destory(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up->num_philos)
	{
		pthread_mutex_destroy(&data->mutexs[i]);
		pthread_mutex_destroy(&data->philos[i].eat_num_event);
		pthread_mutex_destroy(&data->philos[i].eat_time_event);
		i++;
	}
	pthread_mutex_destroy(&data->check_box_event);
	pthread_mutex_destroy(&data->end_check->end_lock);
}

int	main(int ac, char **av)
{
	t_data			*data;
	t_error_type	type;

	data = malloc(sizeof(t_data));
	type = set_philo_data(data, ac, av);
	if (type)
		return (type);
	type = iterate_pthread_create(data);
	if (type)
		return (type);
	watch_threads(data);
	iterate_pthread_join(data);
	mutex_destory(data);
	return (0);
}
