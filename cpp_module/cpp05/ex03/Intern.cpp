/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:27:10 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/06 14:44:17 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(const Intern &src){
	*this = src;
}

Intern::~Intern(){}

Intern &Intern::operator=(const Intern &src){
	(void)src;
	return *this;
}

AForm 	*Intern::makeForm(std::string name, std::string obj){
	int i;
	std::string strArray[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (i = 0; i < 3; i++)
	{
		if (strArray[i] == name)
			break;
	}
	if (i < 3)
		std::cout << "Intern creates " << obj << std::endl;
	switch (i)
	{
		case 0:
			return (new RobotomyRequestForm(obj));
		case 1:
			return new PresidentialPardonForm(obj);
		case 2:
			return new ShrubberyCreationForm(obj);
		default:
			std::cout << name << " is not part of forms!" << std::endl;
			std::cout << "Intern can't create " << obj << std::endl;
			break;
	}
	return NULL;
}
