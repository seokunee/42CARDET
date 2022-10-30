/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:37 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/31 00:07:52 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "utility.h"
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_set_up	t_set_up;

enum e_error_type
{
	ARGS_ERR,
	PARSE_ERR,
	THTREAD_ERR,
};

struct s_set_up
{
	int		num_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		num_must_eat;
	time_t	start_time;
};

struct s_philo
{
	pthread_t		p_thread;
	pthread_mutex_t	event_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				num_eat;
	int				id;
	t_data			*data;
	time_t			last_eat_time;
};

struct s_data
{
	t_set_up		set_up;
	t_philo			**philos;
	pthread_mutex_t	*mutexs;
	pthread_t		*p_thread;
	int				*done_check_box;
};

void			throw_error(enum e_error_type type);

void			iterate_pthread_create(t_data *data);
void			iterate_pthread_detach(t_data *data);

void			*philo_to_do(void *philo);
time_t			get_cur_time(void);

t_philo			**malloc_philos(unsigned int num_philos);
pthread_mutex_t	*malloc_mutex(unsigned int num_philos);

void			set_philo_data(t_data *data, int ac, char **av);
void			set_data_left_each_philo(t_philo **philos, t_data *data);
void			set_forks_each_philo(t_data *data);
void			set_up_init(t_set_up *set_up, int ac, char **av);

int				watch_threads(t_data *data);

void			eating(t_philo *philo);
void			sleeping(t_philo *philo);
void			thinking(t_philo *philo);
void			take_fork(t_philo *philo);

#endif
