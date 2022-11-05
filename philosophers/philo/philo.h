/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:37 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/05 21:25:26 by seokchoi         ###   ########.fr       */
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

# define SHORT_USLEEP_TIME 1000
# define NO_NUM_EAT -2

typedef struct s_data		t_data;
typedef struct s_philo		t_philo;
typedef struct s_set_up		t_set_up;
typedef struct s_end		t_end;
typedef enum e_error_type	t_error;
typedef enum e_to_do_type	t_to_do;

enum e_error_type
{
	ATOI_ERR = -1,
	NO_ERR,
	ARGS_ERR,
	PARSE_ERR,
	THREAD_ERR,
	MUTEX_ERR,
	MALLOC_ERR,
	MUST_EAT_ZERO,
};

enum e_to_do_type
{
	EAT,
	SLEEP,
	THINK,
	TAKE_FORK,
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
	pthread_mutex_t	eat_num_event;
	pthread_mutex_t	eat_time_event;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int				num_eat;
	int				id;
	t_data			*data;
	time_t			last_eat_time;
};

struct s_end
{
	pthread_mutex_t end_lock;
	int				end;
};

struct s_data
{
	t_set_up		set_up;
	t_philo			**philos;
	pthread_t		*p_thread;
	pthread_mutex_t	*mutexs;
	t_end			*end_check;
	pthread_mutex_t check_box_event;
	int				*done_check_box;
};

t_error			throw_error(enum e_error_type type);

t_error			iterate_pthread_create(t_data *data);
t_error			iterate_pthread_detach(t_data *data);

void			*philo_to_do(void *philo);
time_t			get_now_time_ms(void);

t_philo			**malloc_philos(unsigned int num_philos);
pthread_mutex_t	*malloc_mutex(unsigned int num_philos);

t_error			set_philo_data(t_data *data, int ac, char **av);

t_error			set_up_init(t_set_up *set_up, int ac, char **av);

int				watch_threads(t_data *data);
void			while_sleep(time_t time_to_wait);

int				to_do(t_philo *philo, t_to_do type);

void			while_sleep(time_t time_to_wait);
void			usleep_without_error(unsigned int time_to_wait);

time_t			get_now_time_ms(void);
time_t			get_passed_time_ms(time_t start_time);

int				check_game_over(t_philo *philo);

#endif
