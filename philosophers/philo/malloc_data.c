/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:35:33 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 21:13:58 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*malloc_philos(t_data *data)
{
	int	i;

	i = 0;
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
			*type = MUTEX_ERR;
			return (MUTEX_ERR);
		}
		i++;
	}
	return (NO_ERR);
}
