/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/17 21:49:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
void	set_philo_init(t_set_up *set_up, int ac, char **av)
{
	set_up->num_philos = ft_atoi((const char*)av[1]);
	set_up->time_to_die = ft_atoi((const char*)av[2]);
	set_up->time_to_eat = ft_atoi((const char*)av[3]);
	set_up->time_to_sleep = ft_atoi((const char*)av[4]);
	if (ac == 6)
		set_up->num_must_eat = ft_atoi((const char*)av[5]);
}

void	*philo_to_do(void *data)
{
	t_data *info;

	info = (t_data *)data;
	
	pthread_mutex_lock(info->philos[0]);
	
	printf("%s\n", );
	usleep(2000000);
	pthread_mutex_unlock(info->philos[0].);
	return NULL;
}

void	malloc_philos(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo *) * data->set_up.num_philos);
	while (i < data->set_up.num_philos)
	{
		data->philos[i] = malloc(sizeof(t_philo));
		data->philos[i]->id = i;
		i++;
	}
}

void	malloc_mutex(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->
}

int	main(int ac, char **av)
{
	t_data	data;
	(void) ac;
	pthread_t *p_thread;
	int thr_id;
	int status;
	pthread_mutex_t mutex;

	if (ac != 4 || ac != 5)
		exit(1);
	
	set_philo_init(&data.set_up, ac, av);
	p_thread = malloc(sizeof(pthread_t) * data.set_up.num_philos);
	if (pthread_mutex_init(&mutex, NULL))
		exit(1);

	thr_id = pthread_create(&p_thread[0], NULL, philo_to_do, (void *)&data);
	if (thr_id < 0)
		exit(1);
	usleep(1000);
	thr_id = pthread_create(&p_thread[1], NULL, philo_to_do, (void *)&data);
	if (thr_id < 0)
		exit(1);

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	printf("언제 종료 될까요?\n");
	return (0);
}