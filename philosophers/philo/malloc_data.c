/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:35:33 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 02:26:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**malloc_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = (t_philo *)malloc(sizeof(t_philo) * data->set_up->num_philos);
	if (!data->philos)
		return (NULL);
	while (i < data->set_up->num_philos)
	{
		data->philos[i].id = i;
		i++;
	}
	return (&data->philos);
	return (NULL);
}

pthread_mutex_t	*malloc_mutex(unsigned int num_philos)
{
	unsigned int	i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!mutex)
		return (NULL);
	while (i < num_philos)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}
