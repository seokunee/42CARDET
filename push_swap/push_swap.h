/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:45:17 by seokchoi          #+#    #+#             */
/*   Updated: 2022/09/02 19:44:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_data
{
	t_pw_list *list;
}			t_data;

typedef struct s_pw_list
{
	int		value;
	t_pw_list *next;
}			t_pw_list;


# include <unistd.h>
# include <stdlib.h>

# include <stdio.h> // 지울것


#endif