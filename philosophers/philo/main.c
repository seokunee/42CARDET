/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/02 20:23:15 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_all_mutexs(t_data *data)
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
	t_error			type;

	type = set_philo_data(&data, ac, av);
	if (type)
		return (type);
	type = iterate_pthread_create(&data);
	if (type)
		return (type);
	iterate_pthread_detach(&data);
	watch_threads(&data);
	// free_all_mutexs(&data);
	return (0);
}
