/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 23:23:51 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/08 18:36:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eating(t_philo *philo)
{
	time_t	elapsed_time;

	pthread_mutex_lock(&philo->eat_time_event);
	philo->last_eat_time = get_now_time_ms();
	pthread_mutex_unlock(&philo->eat_time_event);
	elapsed_time = philo->last_eat_time - philo->data->set_up->start_time;
	printf("%ld %d is eating\n", elapsed_time, philo->id);
}

static void	sleeping(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_now_time_ms() - philo->data->set_up->start_time;
	printf("%ld %d is sleeping\n", elapsed_time, philo->id);
}

static void	thinking(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_now_time_ms() - philo->data->set_up->start_time;
	printf("%ld %d is thinking\n", elapsed_time, philo->id);
}

static void	take_fork(t_philo *philo)
{
	time_t	elapsed_time;

	elapsed_time = get_now_time_ms() - philo->data->set_up->start_time;
	printf("%ld %d has taken a fork\n", elapsed_time, philo->id);
}

int	to_do(t_philo *philo, t_to_do_type type)
{
	if (check_game_over(philo))
		return (END);
	pthread_mutex_lock(&(philo->data->end_check->end_lock));
	if (type == EAT)
		eating(philo);
	else if (type == SLEEP)
		sleeping(philo);
	else if (type == THINK)
		thinking(philo);
	else if (type == TAKE_FORK)
		take_fork(philo);
	pthread_mutex_unlock(&(philo->data->end_check->end_lock));
	if (check_game_over(philo))
		return (END);
	if (type == EAT)
		while_sleep(philo->data->set_up->time_to_eat);
	else if (type == SLEEP)
		while_sleep(philo->data->set_up->time_to_sleep);
	return (check_game_over(philo));
}
