/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/30 22:15:01 by seokchoi         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data			data;

	set_philo_data(&data, ac, av);
	iterate_pthread_create(&data);
	iterate_pthread_detach(&data);
	watch_threads(&data);
	free_all_mutexs(&data);
	return (0);
}
