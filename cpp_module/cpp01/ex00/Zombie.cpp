/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/09 15:00:25 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){
	name_ = "Extra";
}

Zombie::Zombie(std::string name){
	name_ = name;
}

Zombie::~Zombie(void){
	std::cout << name_ << " zombie is dead" << std::endl;
}

void	Zombie::announce(void){
	std::cout << name_ << " BraiiiiiiinnnzzzZ..." << std::endl;
}
