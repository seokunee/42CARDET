/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:49 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/01 21:15:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_forks_each_philo(t_data *data)
{
	int				i;
	t_philo			**philos;
	pthread_mutex_t	*mutexs;

	philos = data->philos;
	mutexs = data->mutexs;
	i = 0;
	while (i < data->set_up.num_philos)
	{
		if (i == 0)
		{
			philos[0]->r_fork = &mutexs[0];
			philos[0]->l_fork = &mutexs[data->set_up.num_philos - 1];
		}
		else
		{
			philos[i]->r_fork = &mutexs[i];
			philos[i]->l_fork = &mutexs[i - 1];
		}
		i++;
	}
}

t_error	set_data_left_each_philo(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		philos[i]->data = data;
		philos[i]->last_eat_time = data->set_up.start_time;
		philos[i]->id = i + 1;
		philos[i]->num_eat = 0;
		if (pthread_mutex_init(&philos[i]->event_fork, NULL))
			return (MUTEX_ERR);
		i++;
	}
	return (NO_ERR);
}

t_error	check_malloc_data_error(t_data *data)
{
	if (data->p_thread)
		return (MALLOC_ERR);
	if (data->philos)
		return (MALLOC_ERR);
	if (data->mutexs)
		return (MALLOC_ERR);
	if (data->done_check_box)
		return (MALLOC_ERR);
	return (NO_ERR);
}

t_error	set_philo_data(t_data *data, int ac, char **av)
{
	if (set_up_init(&data->set_up, ac, av))
		return (throw_error(ARGS_ERR));
	data->p_thread = malloc(sizeof(pthread_t) * data->set_up.num_philos);
	data->philos = malloc_philos(data->set_up.num_philos);
	data->mutexs = malloc_mutex(data->set_up.num_philos);
	data->done_check_box = ft_calloc(data->set_up.num_philos, sizeof(int));
	if (!check_malloc_data_error(data))
		return (throw_error(MALLOC_ERR));
	if (set_data_left_each_philo(data->philos, data))
		return (throw_error(MUTEX_ERR));
	set_forks_each_philo(data);
	return (NO_ERR);
}
