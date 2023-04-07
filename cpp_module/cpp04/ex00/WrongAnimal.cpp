/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:57:35 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/07 21:22:10 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
	std::cout << "[type :" << _type << "] WrongAnimal constructor is called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	*this = src;
	std::cout << "[type :" << _type << "] WrongAnimal copy constructor is called!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "[type :" << _type << "] WrongAnimal destructor is called!" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
	std::cout << "[type :" << _type << "] WrongAnimal copy assignment operator!" << std::endl;
	if (this == &src)
		return (*this);
	_type = src._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound~" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
