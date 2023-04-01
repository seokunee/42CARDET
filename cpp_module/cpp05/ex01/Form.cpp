/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:15:11 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/01 03:43:28 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() 
	: _name("default"), 
	_grade_signed(150), 
	_grade_execute(150), 
	_signed(false){}

Form::Form(const std::string name, const int grade_signed, const int grade_excute) 
	: _name(name),
	_grade_signed(grade_signed), 
	_grade_execute(grade_excute), 
	_signed(false) {
	if (grade_signed < 1 || grade_excute < 1)
		throw Form::GradeTooHighException();
	if (grade_signed > 150 || grade_excute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &src) 
	: _name(src._name), 
	_grade_signed(src._grade_signed), 
	_grade_execute(src._grade_execute), 
	_signed(src._signed) {}

Form::~Form(){}

Form &Form::operator=(const Form &src){
	_signed = src._signed;
	return (*this);
}

std::string Form::getName() const{
	return (_name);
}

int Form::getGradeSigned() const{
	return (_grade_signed);
}

int Form::getGradeExcute() const{
	return (_grade_execute);
}

bool Form::getSigned() const{
	return (_signed);
}

void	Form::beSigned(const Bureaucrat &obj){
	if (obj.getGrade() > _grade_signed)
		throw Form::GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("grade is too low!");
}

std::ostream &operator<<( std::ostream &o, const Form &i ){
	o << "name is " << i.getName() << ", grade_signed is "
	<< i.getGradeSigned() << ", grade_execute is " << i.getGradeExcute()
	<< ", signed is " << i.getSigned() << "." << std::endl; 
	return o;
}