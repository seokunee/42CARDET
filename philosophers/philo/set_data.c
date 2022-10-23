/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:49 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/23 19:37:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	set_up_init(t_set_up *set_up, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		throw_error(ARGS_ERR);
	set_up->num_philos = ft_atoi((const char*)av[1]);
	set_up->time_to_die = ft_atoi((const char*)av[2]);
	set_up->time_to_eat = ft_atoi((const char*)av[3]);
	set_up->time_to_sleep = ft_atoi((const char*)av[4]);
	if (ac == 6)
		set_up->num_must_eat = ft_atoi((const char*)av[5]);
}

void	set_fork_id_each_philo(t_data *data)
{
	int	i;
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
		philos[i]->id = i;
		i++;
	}
}

void	set_data_address_each_philo(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up.num_philos)
	{
		philos[i]->data = data;
		i++;
	}
}

void	set_philo_data(t_data *data, int ac, char **av)
{
	set_up_init(&data->set_up, ac, av);
	if (data->set_up.num_philos < 2)
		throw_error(ARGS_ERR);
	data->p_thread = malloc(sizeof(pthread_t) * data->set_up.num_philos);
	data->philos = malloc_philos(data->set_up.num_philos);
	data->mutexs = malloc_mutex(data->set_up.num_philos);
	set_data_address_each_philo(data->philos, data);
	set_fork_id_each_philo(data);
}
