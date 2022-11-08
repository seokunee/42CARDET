/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:00 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/08 16:27:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destory_data_mutexs(t_data *data, int j)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->check_box_event);
	pthread_mutex_destroy(&data->end_check->end_lock);
	while (i < data->set_up->num_philos)
	{
		pthread_mutex_destroy(&data->mutexs[i]);
		i++;
	}
	while (--j >= 0)
	{
		pthread_mutex_destroy(&data->philos[j].eat_num_event);
		pthread_mutex_destroy(&data->philos[j].eat_time_event);
	}
}
