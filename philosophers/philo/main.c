/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/05 21:10:55 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*printaa(void *str)
{
	int i = 0;
	usleep(1000000);
	while (i++ < 100)
		printf("%s\n", (char *)str);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_error			type;

	type = set_philo_data(&data, ac, av);
	if (type)
		return (type);
	type = iterate_pthread_create(&data);
	if (type)
		return (type);
	iterate_pthread_detach(&data);
	watch_threads(&data);
	// pthread_t thread;
	// pthread_create(&thread, NULL, printaa, (void *)"hello");
	// pthread_detach(thread);
	// printf("world\n");
	return (0);
}
