/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:09 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/25 22:05:51 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << "[type :" << _type << "] Animal constructor is called!" << std::endl;
}

Animal::Animal(const Animal &src)
{
	*this = src;
	std::cout << "[type :" << _type << "] Animal copy constructor is called!" << std::endl;
}

Animal::~Animal()
{
	std::cout << "[type :" << _type << "] Animal destructor is called!" << std::endl;
}

Animal &Animal::operator=(const Animal &src)
{
	std::cout << "[type :" << _type << "] Animal copy assignment operator!" << std::endl;
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << "Animal sound~" << std::endl;
}

std::string Animal::getType() const
{
	return (_type);
}
