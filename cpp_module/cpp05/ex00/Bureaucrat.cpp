/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/16 15:20:42 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src.getGrade();
	return (*this);
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void Bureaucrat::increment()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade = _grade - 1;
}

void Bureaucrat::decrement()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade = _grade + 1;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low!");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << "." << std::endl;
	return o;
}
