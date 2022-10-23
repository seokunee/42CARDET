/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_to_do.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:30:14 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/23 19:55:44 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_to_do(void *philo)
{
	t_philo			*info;

	info = (t_philo *)philo;
	pthread_mutex_lock(info->l_fork);
	pthread_mutex_lock(info->r_fork);
	
	printf("thread id = %u\n", info->id);
	usleep(20000000);
	
	pthread_mutex_unlock(info->l_fork);
	pthread_mutex_unlock(info->r_fork);
	return NULL;
}
