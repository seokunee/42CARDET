/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/28 14:56:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	*ft_calloc(size_t number, size_t size);
void	ft_bzero(void *s, size_t n);

#endif