/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:48:07 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/08 16:48:26 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo_to_do(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	to_do(philo, TAKE_FORK);
	while (!check_game_over(philo))
		usleep(SHORT_USLEEP_TIME);
	pthread_mutex_unlock(philo->l_fork);
	return (NULL);
}
