/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:37 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/07 02:44:14 by seokchoi         ###   ########.fr       */
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
typedef enum e_error_type	t_error_type;
typedef enum e_to_do_type	t_to_do_type;
typedef enum e_end_type		t_end_type;

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

enum e_end_type
{
	NO_END,
	END,
};
struct s_end
{
	pthread_mutex_t	end_lock;
	t_end_type		end;
};

struct s_data
{
	t_set_up		*set_up;
	t_philo			*philos;
	pthread_mutex_t	*mutexs;
	int				*done_check_box;
	pthread_mutex_t	check_box_event;
	t_end			*end_check;
};

t_error_type		throw_error(enum e_error_type type);

t_error_type		iterate_pthread_create(t_data *data);
t_error_type		iterate_pthread_detach(t_data *data);

void				*philo_to_do(void *philo);
time_t				get_now_time_ms(void);

t_philo				**malloc_philos(t_data *data);
pthread_mutex_t		*malloc_mutex(unsigned int num_philos);

t_error_type		set_philo_data(t_data *data, int ac, char **av);

t_error_type		set_up_init(t_data *data, int ac, char **av);

int					watch_threads(t_data *data);
void				while_sleep(time_t time_to_wait);
t_end_type			check_game_over(t_philo *philo);

int					to_do(t_philo *philo, t_to_do_type type);

void				while_sleep(time_t time_to_wait);
void				usleep_without_error(unsigned int time_to_wait);

time_t				get_now_time_ms(void);
time_t				get_passed_time_ms(time_t start_time);

#endif
