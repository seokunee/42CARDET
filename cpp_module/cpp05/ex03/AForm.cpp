/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:15:11 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/16 15:21:18 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm()
	: _name("default"),
	  _grade_signed(150),
	  _grade_execute(150),
	  _signed(false) {}

AForm::AForm(const std::string name, const int grade_signed, const int grade_excute)
	: _name(name),
	  _grade_signed(grade_signed),
	  _grade_execute(grade_excute),
	  _signed(false)
{
	if (grade_signed < 1 || grade_excute < 1)
		throw AForm::GradeTooHighException();
	if (grade_signed > 150 || grade_excute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &src)
	: _name(src._name),
	  _grade_signed(src._grade_signed),
	  _grade_execute(src._grade_execute),
	  _signed(src._signed) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &src)
{
	_signed = src._signed;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

int AForm::getGradeSigned() const
{
	return (_grade_signed);
}

int AForm::getGradeExcute() const
{
	return (_grade_execute);
}

bool AForm::getSigned() const
{
	return (_signed);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > _grade_signed)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

const char *AForm::ExecuteNotException::what() const throw()
{
	return ("grade_execute is too low!");
}

const char *AForm::SignedIsFalse::what() const throw()
{
	return ("signed is false! get Bureaucrat's sign first!");
}

std::ostream &operator<<(std::ostream &o, const AForm &i)
{
	o << "name is " << i.getName() << ", grade_signed is "
	  << i.getGradeSigned() << ", grade_execute is " << i.getGradeExcute()
	  << ", signed is " << i.getSigned() << "." << std::endl;
	return o;
}
