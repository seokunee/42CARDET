/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:26:04 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/05 02:02:07 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	usleep_without_error(unsigned int time_to_wait)
{
	while (usleep(time_to_wait) != 0)
		;
}

void	while_sleep(time_t time_to_wait)
{
	time_t	start_time;

	start_time = get_now_time_ms();
	while (get_passed_time_ms(start_time) < time_to_wait)
		usleep_without_error(SHORT_USLEEP_TIME);
}
