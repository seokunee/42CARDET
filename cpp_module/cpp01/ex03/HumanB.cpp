/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/09 22:06:28 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void){
}

HumanB::~HumanB(void){
}

HumanB::HumanB(std::string name){
	name_ = name;
}

void	HumanB::attack(void){
	std::cout << name_ << "attacks with his " << weapon_->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon){
	weapon_ = weapon;
}