/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:05 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/25 21:29:23 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal(){
	_type = "Cat";
	_brain = new Brain();
	std::cout << "[type :" << _type << "] Cat constructor is called!" << std::endl;
}

Cat::Cat(const Cat &src){
	_brain = new Brain();
	*this = src;
	std::cout << "[type :" << _type << "] Cat copy constructor is called!" << std::endl;
}

Cat::~Cat(){
	std::cout << "[type :" << _type << "] Cat destructor is called!" << std::endl;
	delete (_brain);
}

Cat &Cat::operator=(const Cat &src){
	_type = src._type;
	*_brain = *(src._brain);
	std::cout << "[type :" << _type << "] Cat copy assignment operator!" << std::endl;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow Meow~" << std::endl;
}