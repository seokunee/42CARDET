/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:27:10 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/14 17:18:39 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return *this;
}

AForm *Intern::makeForm(std::string form, std::string target)
{
	int i;
	std::string strArray[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	for (i = 0; i < 3; i++)
	{
		if (strArray[i] == form)
			break;
	}
	if (i < 3)
		std::cout << "Intern creates " << target << std::endl;
	switch (i)
	{
	case 0:
		return new RobotomyRequestForm(target);
	case 1:
		return new PresidentialPardonForm(target);
	case 2:
		return new ShrubberyCreationForm(target);
	default:
		std::cout << form << " is not part of forms!" << std::endl;
		std::cout << "Intern can't create " << target << std::endl;
		break;
	}
	return NULL;
}
