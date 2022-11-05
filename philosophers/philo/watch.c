/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:13:51 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/05 17:06:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_die(t_data *data, int *flag)
{
	int		i;
	time_t	elapsed_time;

	i = -1;
	while (++i < data->set_up.num_philos)
	{
		pthread_mutex_lock(&data->philos[i]->eat_time_event);
		if (get_now_time_ms() - data->philos[i]->last_eat_time \
		> data->set_up.time_to_die)
		{
			pthread_mutex_lock(&(data->end_lock));
			*flag = 0;
			elapsed_time = get_now_time_ms() - \
			data->philos[i]->data->set_up.start_time;
			printf("%ld %d died\n", elapsed_time, data->philos[i]->id);
			break ;
		}
		pthread_mutex_unlock(&data->philos[i]->eat_time_event);
	}
}

static void	check_done_all(t_data *data, int *flag)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&(data->check_box_event));
	if (data->set_up.num_must_eat != -1)
	{
		while (++i < data->set_up.num_philos)
		{
			if (data->done_check_box[i] == 0)
				break ;
			if (i == data->set_up.num_philos - 1)
			{
				pthread_mutex_lock(&(data->end_lock));
				*flag = 0;
			}
		}
	}
	pthread_mutex_unlock(&(data->check_box_event));
}

int	watch_threads(t_data *data)
{
	int	flag;

	flag = 1;
	while (flag)
	{
		check_die(data, &flag);
		if (flag == 0)
			break ;
		check_done_all(data, &flag);
	}
	return (0);
}
