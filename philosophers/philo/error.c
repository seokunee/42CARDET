/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:46:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/30 23:35:05 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	throw_error(enum e_error_type type)
{
	if (type == ARGS_ERR)
		ft_putstr_fd("ERROR : ARGS_ERR\n", 2);
	else if (type == PARSE_ERR)
		ft_putstr_fd("ERROR : PARSE_ERR\n", 2);
	else if (type == THTREAD_ERR)
		ft_putstr_fd("ERROR : THTREAD_ERR\n", 2);
	exit(1);
}
