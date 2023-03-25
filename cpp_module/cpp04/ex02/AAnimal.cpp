/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:09 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/25 22:04:46 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal"){
	std::cout << "[type :" << _type << "] AAnimal constructor is called!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src){
	*this = src;
	std::cout << "[type :" << _type << "] AAnimal copy constructor is called!" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "[type :" << _type << "] AAnimal destructor is called!" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &src){
	_type = src._type;
	std::cout << "[type :" << _type << "] AAnimal copy assignment operator!" << std::endl;
	return (*this);
}

std::string AAnimal::getType() const{
	return (_type);
}
