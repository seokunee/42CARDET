/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:46:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/06 15:09:39 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_error_type	throw_error(enum e_error_type type)
{
	if (type == ARGS_ERR)
		ft_putstr_fd("ERROR : ARGS_ERR\n", 2);
	else if (type == PARSE_ERR)
		ft_putstr_fd("ERROR : PARSE_ERR\n", 2);
	else if (type == THREAD_ERR)
		ft_putstr_fd("ERROR : THREAD_ERR\n", 2);
	else if (type == MALLOC_ERR)
		ft_putstr_fd("ERROR : MALLOC_ERR\n", 2);
	else if (type == MUTEX_ERR)
		ft_putstr_fd("ERROR : MUTEX_ERR\n", 2);
	return (type);
}
