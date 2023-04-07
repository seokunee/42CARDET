/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:03 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 21:22:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	_type = "Dog";
	std::cout << "[type :" << _type << "] Dog constructor is called!" << std::endl;
}

Dog::Dog(const Dog &src)
{
	*this = src;
	std::cout << "[type :" << _type << "] Dog copy constructor is called!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "[type :" << _type << "] Dog destructor is called!" << std::endl;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "[type :" << _type << "] Dog copy assignment operator!" << std::endl;
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
