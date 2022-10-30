/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:35:33 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/31 01:24:28 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**malloc_philos(unsigned int num_philos)
{
	unsigned int	i;
	t_philo			**philos;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * num_philos);
	if (!philos)
		return (NULL);
	while (i < num_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!philos[i])
			return (NULL);
		philos[i]->id = i;
		i++;
	}
	return (philos);
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
