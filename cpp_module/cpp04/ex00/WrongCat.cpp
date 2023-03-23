/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:11:37 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/23 18:31:12 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	_type = "WrongCat";
	std::cout << "[type :" << _type << "] WrongCat constructor is called!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src){
	*this = src;
	std::cout << "[type :" << _type << "] WrongCat copy constructor is called!" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "[type :" << _type << "] WrongCat destructor is called!" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &src){
	_type = src._type;
	std::cout << "[type :" << _type << "] WrongCat a!" << std::endl;
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "Meow Meow~" << std::endl;
}
