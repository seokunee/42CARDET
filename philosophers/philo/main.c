/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:05:02 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/18 17:49:54 by seokchoi         ###   ########.fr       */
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
	unsigned int	id;

	info = (t_philo *)philo;
	pthread_mutex_lock(info->philos[0);
	
	printf("%s\n", info->philos[0].);
	usleep(2000000);
	pthread_mutex_unlock(info->philos[0]);
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
			philos[0]->r_fork = mutexs[0];
			philos[0]->l_fork = mutexs[data->set_up.num_philos - 1];
		}
		else if (i == data->set_up.num_philos - 1)
		{

		}
		else
		{
			
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

	if (ac != 4 || ac != 5)
		exit(1);

	set_philo_init(&data.set_up, ac, av);
	if (data.set_up.num_philos < 2)
		exit(1);
	data.philos = malloc_philos(data.set_up.num_philos);
	data.mutexs = malloc_mutex(data.set_up.num_philos);

	thr_id = pthread_create(&p_thread[0], NULL, philo_to_do, (void *)data.philos[0]);
	if (thr_id < 0)
		exit(1);
	usleep(1);
	thr_id = pthread_create(&p_thread[1], NULL, philo_to_do, (void *)data.philos[1]);
	if (thr_id < 0)
		exit(1);
	usleep(1);
	if (pthread_mutex_init(&mutex, NULL))
		exit(1);

	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	printf("언제 종료 될까요?\n");
	return (0);
}

/*

thread 함수가 동작하기 위해서 필요한 것은? 뮤텍스
1. 
2. 

*/