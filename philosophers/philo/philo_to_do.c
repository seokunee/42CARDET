/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/27 22:02:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_cur_time()
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	eating(t_philo *philo)
{
	time_t	elapsed_time;
	
	philo->last_eat_time = get_cur_time();
	elapsed_time = philo->last_eat_time - philo->data->set_up.start_time;
	printf("%ld %d is eating\n", elapsed_time, philo->id);
	usleep(philo->data->set_up.time_to_eat * 1000);
}

void	sleeping(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_cur_time() - philo->data->set_up.start_time;
	printf("%ld %d is sleeping\n", elapsed_time, philo->id);
	usleep(philo->data->set_up.time_to_sleep);
}

void	thinking(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_cur_time() - philo->data->set_up.start_time;
	printf("%ld %d is thinking\n", elapsed_time, philo->id);
}

void	take_fork(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_cur_time() - philo->data->set_up.start_time;
	printf("%ld %d has taken a fork\n", elapsed_time, philo->id);
}

int	count_eat(t_philo *philo)
{
	philo->num_eat++;
	if (philo->num_eat == philo->data->set_up.num_must_eat)
		return (1);
	return (0);
}

void	*philo_to_do(void *philo)
{
	t_philo			*info;

	info = (t_philo *)philo;
	if (info->id % 2 == 0)
		usleep(100000);
	while (1)
	{
		pthread_mutex_lock(info->l_fork);
		take_fork(philo);
		pthread_mutex_lock(info->r_fork);
		take_fork(philo);
		eating(philo);
		pthread_mutex_unlock(info->l_fork);
		pthread_mutex_unlock(info->r_fork);
		if (count_eat(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

