/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 21:21:59 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	_type = "Cat";
	std::cout << "[type :" << _type << "] Cat constructor is called!" << std::endl;
}

Cat::Cat(const Cat &src)
{
	*this = src;
	std::cout << "[type :" << _type << "] Cat copy constructor is called!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "[type :" << _type << "] Cat destructor is called!" << std::endl;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "[type :" << _type << "] Cat copy assignment operator!" << std::endl;
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow~" << std::endl;
}
