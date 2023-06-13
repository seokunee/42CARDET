/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:25:17 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/14 02:27:50 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
// #include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomy_request_form", 72, 45), _target("de_target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy_request_form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	_target = src.getTarget();
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getSigned()))
	{
		throw RobotomyRequestForm::SignedIsFalse();
	}
	else if (executor.getGrade() > this->getGradeExcute())
	{
		throw RobotomyRequestForm::ExecuteNotException();
	}
	std::srand(std::time(NULL));
	std::cout << "drilling...asl.efa.se.fsdf.a.ef" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	else
		std::cout << _target << " has been robotomized failed!" << std::endl;
}

std::ostream &operator<<(std::ostream &o, const RobotomyRequestForm &i)
{
	o << "target is " << i.getTarget() << "." << std::endl;
	return o;
}
