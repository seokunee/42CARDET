/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _main0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:41:27 by seokchoi          #+#    #+#             */
/*   Updated: 2022/04/12 17:47:03 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
# include <fcntl.h>

int	main(void)
{
	printf("%s", get_next_line(0));
	return (0);
}