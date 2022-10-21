/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:29:37 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/21 15:10:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>




#include <stdio.h> // --------------


enum error_type
{
	ARGS_ERR,
	PARSE_ERR,
};

typedef struct s_set_up
{
	int	num_philos;
	int time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_must_eat;
}	t_set_up;

typedef struct s_philo
{
	pthread_t p_thread;
	pthread_mutex_t *l_fork;
	pthread_mutex_t *r_fork;
	unsigned int id;
}	t_philo;

typedef struct s_data
{
	t_set_up		set_up;
	t_philo			**philos;
	pthread_mutex_t	*mutexs;
	pthread_t		*p_thread;
}	t_data;

void	throw_error(char *message);

#endif
