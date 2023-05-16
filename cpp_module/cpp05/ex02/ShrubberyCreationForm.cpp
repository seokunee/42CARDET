/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:24:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/16 15:21:13 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("a_form", 145, 137), _target("de_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("a_form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	_target = src.getTarget();
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream writeFile;
	std::string ascii_tree =
		"               *\n"
		"              ***\n"
		"             *****\n"
		"            *******\n"
		"           *********\n"
		"          ***********\n"
		"         *************\n"
		"        ***************\n"
		"       *****************\n"
		"      *******************\n"
		"     *********************\n"
		"    ***********************\n"
		"   *************************\n"
		"  ***************************\n"
		"             |||||\n"
		"             |||||\n"
		"             |||||\n"
		"             |||||\n"
		"             |||||\n"
		"             |||||\n";

	if (!(this->getSigned()))
	{
		throw ShrubberyCreationForm::SignedIsFalse();
	}
	else if (executor.getGrade() > this->getGradeExcute())
	{
		throw ShrubberyCreationForm::ExecuteNotException();
	}
	writeFile.open(_target + "_shrubbery");
	if (writeFile.is_open() == true)
	{
		writeFile << ascii_tree;
	}
	else
	{
		throw ShrubberyCreationForm::CantOpenFile();
	}
	writeFile.close();
}

const char *ShrubberyCreationForm::CantOpenFile::what() const throw()
{
	return ("Failed open file!");
}

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &i)
{
	o << "target is " << i.getTarget() << "." << std::endl;
	return o;
}
