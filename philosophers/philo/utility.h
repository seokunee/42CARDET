/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/11/01 21:29:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t number, size_t size);

#endif