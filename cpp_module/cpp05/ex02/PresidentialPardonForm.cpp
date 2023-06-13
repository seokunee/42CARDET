/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:25:12 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/14 02:27:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("presidential_pardon_form", 25, 5), _target("de_target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("presidential_pardon_form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	_target = src.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!(this->getSigned()))
	{
		throw PresidentialPardonForm::SignedIsFalse();
	}
	else if (executor.getGrade() > this->getGradeExcute())
	{
		throw PresidentialPardonForm::ExecuteNotException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &o, const PresidentialPardonForm &i)
{
	o << "target is " << i.getTarget() << "." << std::endl;
	return o;
}
