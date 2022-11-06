/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 02:28:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data 		*data;
	t_error_type type;

	data = malloc(sizeof(t_data));
	type = set_philo_data(data, ac, av);
	if (type)
	  return (type);
	type = iterate_pthread_create(data);
	if (type)
	  return (type);
	iterate_pthread_detach(data);
	watch_threads(data);
	return (0);
}
