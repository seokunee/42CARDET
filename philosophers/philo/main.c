/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/16 19:34:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	set_philo_init(t_philo *philo, int ac, char **av)
{
	philo->num_philos = ft_atoi((const char*)av[1]);
	philo->time_to_die = ft_atoi((const char*)av[2]);
	philo->time_to_eat = ft_atoi((const char*)av[3]);
	philo->time_to_sleep = ft_atoi((const char*)av[4]);
	if (ac == 6)
		philo->num_must_eat = ft_atoi((const char*)av[5]);
}

void	philo_to_do(void *str)
{
	printf("%s\n", (char *)str);
}

int	main(int ac, char **av)
{
	t_philo	philo;
	(void) ac;
	pthread_t *p_thread;
	int thr_id;
	int status;

	char p1[] = "thread 1";
	char p2[] = "thread 2";
	set_philo_init(&philo, ac, av);
	p_thread = malloc(sizeof(pthread_t) * philo.num_philos);
	usleep(1000);
	thr_id = pthread_create(&p_thread[0], NULL, philo_to_do, (void *)p1);
	if (thr_id < 0)
		exit(1);
	thr_id = pthread_create(&p_thread[1], NULL, philo_to_do, (void *)p2);
	if (thr_id < 0)
		exit(1);
	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	printf("언제 종료 될까요?\n");
	return (0);
}