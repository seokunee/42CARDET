/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 17:11:45 by seokchoi          #+#    #+#             */
/*   Updated: 2022/10/24 15:38:33 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_H
# define UTILITY_H

# include <unistd.h>

int		ft_atoi(const char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);

#endif