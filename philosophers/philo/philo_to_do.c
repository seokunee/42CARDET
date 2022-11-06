/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 02:34:56 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	count_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_num_event);
	philo->num_eat++;
	pthread_mutex_unlock(&philo->eat_num_event);
	if (philo->num_eat == philo->data->set_up->num_must_eat)
	{
		pthread_mutex_lock(&philo->data->check_box_event);
		philo->data->done_check_box[philo->id - 1] = 1;
		pthread_mutex_unlock(&philo->data->check_box_event);
		return (1);
	}
	return (0);
}

static void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	to_do(philo, TAKE_FORK);
	pthread_mutex_lock(philo->r_fork);
	to_do(philo, TAKE_FORK);
}

static void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static int	count_eat_num(t_philo *philo, int *stop)
{
	if (philo->data->set_up->num_must_eat >= 0 && count_eat(philo))
		*stop = 0;
	return (check_game_over(philo));
}

void	*philo_to_do(void *philo)
{
	int				stop;

	stop = 1;
	while (stop)
	{
		take_forks(philo);
		if (to_do(philo, EAT))
			return (NULL);
		put_down_forks(philo);
		if (count_eat_num(philo, &stop))
			return (NULL);
		if (to_do(philo, SLEEP))
			return (NULL);
		if (to_do(philo, THINK))
			return (NULL);
	}
	return (NULL);
}
