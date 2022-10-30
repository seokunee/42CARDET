/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:49 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/31 00:07:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_up_init(t_set_up *set_up, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		throw_error(ARGS_ERR);
	set_up->num_philos = ft_atoi((const char *)av[1]);
	set_up->time_to_die = ft_atoi((const char *)av[2]);
	set_up->time_to_eat = ft_atoi((const char *)av[3]);
	set_up->time_to_sleep = ft_atoi((const char *)av[4]);
	set_up->num_must_eat = -1;
	if (ac == 6)
		set_up->num_must_eat = ft_atoi((const char *)av[5]);
	set_up->start_time = get_cur_time();
}

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

void	set_data_left_each_philo(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		philos[i]->data = data;
		philos[i]->last_eat_time = data->set_up.start_time;
		philos[i]->id = i + 1;
		philos[i]->num_eat = 0;
		pthread_mutex_init(&philos[i]->event_fork, NULL);
		i++;
	}
}

void	set_philo_data(t_data *data, int ac, char **av)
{
	set_up_init(&data->set_up, ac, av);
	data->p_thread = malloc(sizeof(pthread_t) * data->set_up.num_philos);
	data->philos = malloc_philos(data->set_up.num_philos);
	data->mutexs = malloc_mutex(data->set_up.num_philos);
	data->done_check_box = ft_calloc(data->set_up.num_philos, sizeof(int));
	set_data_left_each_philo(data->philos, data);
	set_forks_each_philo(data);
}
