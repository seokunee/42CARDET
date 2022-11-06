/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:26:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 02:05:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_type	iterate_pthread_create(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->set_up->num_philos)
	{
		status = pthread_create(&data->philos[i].p_thread, \
		NULL, philo_to_do, &data->philos[i]);
		if (status < 0)
			return (THREAD_ERR);
		i += 2;
	}
	usleep_without_error(SHORT_USLEEP_TIME);
	i = 1;
	while (i < data->set_up->num_philos)
	{
		status = pthread_create(&data->philos[i].p_thread, \
		NULL, philo_to_do, &data->philos[i]);
		if (status < 0)
			return (throw_error(THREAD_ERR));
		i += 2;
	}
	return (NO_ERR);
}

t_error_type	iterate_pthread_detach(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up->num_philos)
	{
		pthread_detach(data->philos[i].p_thread);
		i++;
	}
	return (NO_ERR);
}
