/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:51:39 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/30 03:32:35 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "AMateria.hpp"

// AMateria::AMateria() : _type("none"){}

// AMateria::AMateria(const AMateria &src){
// 	*this = src;
// }

// AMateria::AMateria(std::string const &type) : _type(type){}

// AMateria::~AMateria(){}

// AMateria &AMateria::operator=(const AMateria &src){
// 	_type = src._type;
// 	return (*this);
// }

// std::string const &AMateria::getType() const{
// 	return (_type);
// }

// void AMateria::use(ICharacter& target){
// 	(void)target;
// }


#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(AMateria const& obj) : _type(obj._type) {}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
  return _type;
}

void AMateria::use(ICharacter& target) {
  (void)target;
}
