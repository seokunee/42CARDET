/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:03 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/25 21:29:30 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal(){
	_type = "Dog";
	_brain = new Brain();
	std::cout << "[type :" << _type << "] Dog constructor is called!" << std::endl;
}

Dog::Dog(const Dog &src){
	_brain = new Brain();
	*this = src;
	std::cout << "[type :" << _type << "] Dog copy constructor is called!" << std::endl;
}

Dog::~Dog(){
	std::cout << "[type :" << _type << "] Dog destructor is called!" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(const Dog &src){
	_type = src._type;
	*_brain = *(src._brain);
	std::cout << "[type :" << _type << "] Dog copy assignment operator!" << std::endl;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Woof! Woof!" << std::endl;
}