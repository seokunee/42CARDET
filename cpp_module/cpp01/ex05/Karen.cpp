/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 21:36:16 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/09 01:54:20 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen(void){
}

Karen::~Karen(void){
}

void Karen::debug(void){
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info(void){
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning(void){
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error(void){
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level){
	void (Karen::*ptr[4])(void) = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error};
	std::string type[4] = {"debug", "info", "warning", "error"};
	
	for (int i = 0; i < 4; i++){
		if (level == type[i])
			(this->*ptr[i])();
	}
}