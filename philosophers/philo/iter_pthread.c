/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter_pthread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:26:50 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/28 20:05:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	iterate_pthread_create(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		status = pthread_create(&data->philos[i]->p_thread, NULL, philo_to_do, (void *)data->philos[i]);
		if (status < 0)
			throw_error(THTREAD_ERR);
		data->philos[i]->p_thread = data->p_thread[i];
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->set_up.num_philos)
	{
		status = pthread_create(&data->philos[i]->p_thread, NULL, philo_to_do, (void *)data->philos[i]);
		if (status < 0)
			throw_error(THTREAD_ERR);
		data->philos[i]->p_thread = data->p_thread[i];
		i += 2;
	}
}

void	iterate_pthread_detach(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < data->set_up.num_philos)
	{
		pthread_detach(data->philos[i]->p_thread);
		i++;
	}
}
