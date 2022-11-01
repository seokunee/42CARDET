/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:24:53 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/01 21:15:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_now_time_ms(void)
{
	struct timeval	time;

	while (1)
	{
		if (gettimeofday(&time, NULL) == 0)
			break ;
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

time_t	get_passed_time_ms(time_t start_time)
{
	return (get_now_time_ms() - start_time);
}
