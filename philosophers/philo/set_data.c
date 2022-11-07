/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:30:49 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 21:16:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_forks_each_philo(t_data *data)
{
	int				i;
	t_philo			*philos;
	pthread_mutex_t	*mutexs;

	philos = data->philos;
	mutexs = data->mutexs;
	i = 0;
	while (i < data->set_up->num_philos)
	{
		if (i == 0)
		{
			philos[0].r_fork = &mutexs[0];
			philos[0].l_fork = &mutexs[data->set_up->num_philos - 1];
		}
		else
		{
			philos[i].r_fork = &mutexs[i];
			philos[i].l_fork = &mutexs[i - 1];
		}
		i++;
	}
}

static t_error_type	set_info_of_philo(t_philo *philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->set_up->num_philos)
	{
		philos[i].data = data;
		philos[i].last_eat_time = data->set_up->start_time;
		philos[i].id = i + 1;
		philos[i].num_eat = 0;
		if (pthread_mutex_init(&philos[i].eat_num_event, NULL))
			return (MUTEX_ERR);
		if (pthread_mutex_init(&philos[i].eat_time_event, NULL))
			return (MUTEX_ERR);
		i++;
	}
	return (NO_ERR);
}

static t_error_type	malloc_done_check_box(t_data *data)
{
	data->done_check_box = ft_calloc(data->set_up->num_philos, sizeof(int));
	if (!data->done_check_box)
		return (MALLOC_ERR);
	return (NO_ERR);
}

static t_error_type	set_end_struct(t_data *data, t_error_type *type)
{
	t_end	*end;

	end = malloc(sizeof(t_end));
	if (!end)
	{
		*type = MALLOC_ERR;
		return (MALLOC_ERR);
	}
	if (pthread_mutex_init(&end->end_lock, NULL))
	{
		*type = MUTEX_ERR;
		return (MUTEX_ERR);
	}
	end->end = NO_END;
	data->end_check = end;
	return (NO_ERR);
}

t_error_type	set_philo_data(t_data *data, int ac, char **av)
{
	t_error_type	type;

	if (set_up_init(data, ac, av, &type))
		return (throw_error(type));
	if (data->set_up->num_must_eat == 0)
		return (MUST_EAT_ZERO);
	if (!malloc_philos(data))
		return (throw_error(MALLOC_ERR));
	if (malloc_mutex(data, &type))
		return (throw_error(type));
	if (malloc_done_check_box(data))
		return (throw_error(MALLOC_ERR));
	if (pthread_mutex_init(&data->check_box_event, NULL))
		return (throw_error(MUTEX_ERR));
	if (set_end_struct(data, &type))
		return (throw_error(type));
	if (set_info_of_philo(data->philos, data))
		return (throw_error(MUTEX_ERR));
	set_forks_each_philo(data);
	return (NO_ERR);
}
