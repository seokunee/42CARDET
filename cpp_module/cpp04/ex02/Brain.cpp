/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:20:23 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 21:29:31 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor is called!" << std::endl;
}

Brain::Brain(const Brain &src)
{
	*this = src;
	std::cout << "Brain copy constructor is called!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor is called!" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	std::cout << "Brain copy assignment operator!" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
		_ideas[i] = src._ideas[i];
	return (*this);
}
