/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:37 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/23 19:38:02 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "utility.h"
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>

#include <stdio.h> // -----지울것-----

typedef struct s_data t_data;
typedef struct s_philo t_philo;
typedef struct s_set_up t_set_up;

enum error_type
{
	ARGS_ERR,
	PARSE_ERR,
	THTREAD_ERR,
};

struct s_set_up
{
	int	num_philos;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
};

struct s_philo
{
	pthread_t		p_thread;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	int				id;
	t_data			*data;
};

struct s_data
{
	t_set_up		set_up;
	t_philo			**philos;
	pthread_mutex_t	*mutexs;
	pthread_t		*p_thread;
};

void			throw_error(enum error_type type);

// iterate_pthread
void			iterate_pthread_create(t_data *data);
void			iterate_pthread_join(t_data *data);

//philo_to_do
void			*philo_to_do(void *philo);

// malloc_data
t_philo			**malloc_philos(unsigned int num_philos);
pthread_mutex_t	*malloc_mutex(unsigned int num_philos);

// set_data
void			set_philo_data(t_data *data, int ac, char **av);
void			set_data_address_each_philo(t_philo **philos, t_data *data);
void			set_fork_id_each_philo(t_data *data);
void			set_up_init(t_set_up *set_up, int ac, char **av);


#endif
