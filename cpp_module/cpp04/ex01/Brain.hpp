/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:02:56 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:05:44 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
protected:
	std::string _ideas[100];

public:
	Brain();
	Brain(const Brain &src);
	~Brain();

	Brain &operator=(const Brain &src);
};

#endif
