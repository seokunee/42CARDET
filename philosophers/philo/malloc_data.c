/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:35:33 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/26 01:12:24 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*malloc_philos(t_data *data)
{
	data->philos = (t_philo *)malloc(sizeof(t_philo) \
			* data->set_up->num_philos);
	if (!data->philos)
		return (NULL);
	return (data->philos);
}

t_error_type	malloc_mutex(t_data *data, t_error_type *type)
{
	int	i;

	i = 0;
	*type = MUTEX_ERR;
	data->mutexs = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* data->set_up->num_philos);
	if (!data->mutexs)
	{
		*type = MALLOC_ERR;
		return (MALLOC_ERR);
	}
	while (i < data->set_up->num_philos)
	{
		if (pthread_mutex_init(&data->mutexs[i], NULL))
		{
			while (--i >= 0)
				pthread_mutex_destroy(&data->mutexs[i]);
			pthread_mutex_destroy(&data->check_box_event);
			pthread_mutex_destroy(&data->end_check->end_lock);
			return (MUTEX_ERR);
		}
		i++;
	}
	return (NO_ERR);
}
