/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:26:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/08 18:10:01 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_error_type	operate_thread(t_data *data, int i)
{
	int	status;

	while (i < data->set_up->num_philos)
	{
		status = pthread_create(&data->philos[i].p_thread, \
		NULL, philo_to_do, &data->philos[i]);
		if (status < 0)
			return (THREAD_ERR);
		i += 2;
	}
	return (NO_ERR);
}

t_error_type	iterate_pthread_create(t_data *data)
{
	operate_thread(data, 0);
	usleep_without_error(SHORT_USLEEP_TIME);
	operate_thread(data, 1);
	return (NO_ERR);
}

t_error_type	iterate_pthread_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up->num_philos)
	{
		pthread_join(data->philos[i].p_thread, NULL);
		i++;
	}
	return (NO_ERR);
}
