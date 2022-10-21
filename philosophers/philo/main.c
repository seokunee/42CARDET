/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/21 18:28:55 by seokchoi         ###   ########.fr       */
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

void	*philo_to_do(void *philo)
{
	t_philo			*info;

	info = (t_philo *)philo;
	pthread_mutex_lock(info->l_fork);
	pthread_mutex_lock(info->r_fork);
	
	printf("thread id = %u\n", info->id);
	usleep(2000000);
	
	pthread_mutex_unlock(info->l_fork);
	pthread_mutex_unlock(info->r_fork);
	return NULL;
}

t_philo	**malloc_philos(unsigned int num_philos)
{
	unsigned int	i;
	t_philo	**philos;

	i = 0;
	philos = (t_philo **)malloc(sizeof(t_philo *) * num_philos);
	while (i < num_philos)
	{
		philos[i] = (t_philo *)malloc(sizeof(t_philo));
		philos[i]->id = i;
		i++;
	}
	return (philos);
}

pthread_mutex_t	*malloc_mutex(unsigned int num_philos)
{
	unsigned int	i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num_philos);
	while (i < num_philos)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (mutex);
}

// void	create_thread(t_)
// {
// 	int	i;
// 	i = 0;

// 	while (i < data.set_up.num_philos)
// 	{
// 		thr_id = pthread_create(&p_thread[i], NULL, philo_to_do, (void *)data.philos[i]);
// 		if (thr_id < 0)
// 			exit(1);
// 		usleep(1);
// 	}
// }

void	set_fork_each_philo(t_data *data)
{
	int				i;
	t_philo			**philos;
	pthread_mutex_t	*mutexs;

	philos = data->philos;
	mutexs = data->mutexs;
	i = 0;
	while (i < data->set_up.num_philos)
	{
		if (i == 0)
		{
			philos[0]->r_fork = &mutexs[0];
			philos[0]->l_fork = &mutexs[data->set_up.num_philos - 1];
		}
		else
		{
			philos[i]->r_fork = &mutexs[i];
			philos[i]->l_fork = &mutexs[i - 1];
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	(void) ac;
	int thr_id;
	int status;
	pthread_mutex_t mutex;

	printf("aa\n");

	if (ac != 5 && ac != 6)
		exit(1);
	printf("a\n");
	set_philo_init(&data.set_up, ac, av);
	printf("b\n");

	if (data.set_up.num_philos < 2)
		exit(1);
	printf("c\n");
	
	data.philos = malloc_philos(data.set_up.num_philos);
	data.mutexs = malloc_mutex(data.set_up.num_philos);
	printf("d\n");

	set_fork_each_philo(&data);
	printf("e\n");

	thr_id = pthread_create(&data.philos[0]->p_thread, NULL, philo_to_do, (void *)data.philos[0]);
	if (thr_id < 0)
		exit(1);
	usleep(10);
	printf("f\n");
	printf("ff %d\n", status);

	thr_id = pthread_create(&data.philos[1]->p_thread, NULL, philo_to_do, (void *)data.philos[1]);
	if (thr_id < 0)
		exit(1);
	usleep(10);
	printf("g\n");
	
	if (pthread_mutex_init(&mutex, NULL))
		exit(1);
	pthread_join(data.philos[0]->p_thread, (void **)&status);
	pthread_join(data.philos[1]->p_thread, (void **)&status);
	printf("언제 종료 될까요?\n");
	return (0);
}
