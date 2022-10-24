/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/24 20:26:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

struct timeval	get_cur_time()
{
	
}

void	eating(t_philo *philo)
{
	int	time_to_eat = philo->data->set_up.time_to_eat;
	ft_putstr_fd("thread ", 1);
	ft_putnbr_fd(time_to_eat, 1);
	ft_putstr_fd(" is eating...\n", 1);
	usleep(time_to_eat);
}

void	sleeping(t_philo *philo)
{
	int	time_to_sleep = philo->data->set_up.time_to_sleep;
	ft_putstr_fd("thread ", 1);
	ft_putnbr_fd(time_to_sleep, 1);
	ft_putstr_fd(" is sleeping...", 1);
	usleep(time_to_sleep);
}

void	thinking(t_philo *philo)
{
	
}

void	count_eat(t_philo *philo)
{
	
}

void	*philo_to_do(void *philo)
{
	t_philo			*info;

	info = (t_philo *)philo;
	if (info->id % 2 != 0)
		usleep(1);
	while (1)
	{
		pthread_mutex_lock(info->l_fork);
		pthread_mutex_lock(info->r_fork);

		eating(philo);
		get_cur_time();
		
		pthread_mutex_unlock(info->l_fork);
		pthread_mutex_unlock(info->r_fork);
		count_eat(philo);
		if (count_)
		sleeping(philo);
	}
	return (NULL);
}
