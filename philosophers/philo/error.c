/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:46:35 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/23 17:08:31 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	throw_error(enum error_type type)
{
	if (type == ARGS_ERR)
		ft_putstr_fd("ERROR : ARGS_ERR\n", 2);
	else if (type == PARSE_ERR)
		ft_putstr_fd("ERROR : PARSE_ERR\n", 2);
	else if (type == THTREAD_ERR)
		ft_putstr_fd("ERROR : THTREAD_ERR\n", 2);
	exit(1);
}
