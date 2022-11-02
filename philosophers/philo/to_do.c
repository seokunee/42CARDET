/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:23:51 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/02 20:55:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_to_do(t_philo *philo, t_to_do type)
{
	
}

void	eating(t_philo *philo)
{
	time_t	elapsed_time;

	pthread_mutex_lock(&philo->event);
	philo->last_eat_time = get_now_time_ms();
	elapsed_time = philo->last_eat_time - philo->data->set_up.start_time;
	printf("%ld %d is eating\n", elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->event);
	while_sleep(philo->data->set_up.time_to_eat);
}

void	sleeping(t_philo *philo)
{
	time_t	elapsed_time;

	pthread_mutex_lock(&philo->event);
	elapsed_time = get_now_time_ms() - philo->data->set_up.start_time;
	printf("%ld %d is sleeping\n", elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->event);
	while_sleep(philo->data->set_up.time_to_sleep);
}

void	thinking(t_philo *philo)
{
	time_t	elapsed_time;

	pthread_mutex_lock(&philo->event);
	elapsed_time = get_now_time_ms() - philo->data->set_up.start_time;
	printf("%ld %d is thinking\n", elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->event);
}

void	take_fork(t_philo *philo)
{
	time_t	elapsed_time;

	pthread_mutex_lock(&philo->event);
	elapsed_time = get_now_time_ms() - philo->data->set_up.start_time;
	printf("%ld %d has taken a fork\n", elapsed_time, philo->id);
	pthread_mutex_unlock(&philo->event);
}
