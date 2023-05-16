/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:24:38 by seokchoi          #+#    #+#             */
/*   Updated: 2023/05/16 15:21:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;
	ShrubberyCreationForm();

public:
	class CantOpenFile : public std::exception
	{
	public:
		const char *what() const throw();
	};
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	std::string getTarget() const;
	void execute(Bureaucrat const &executor) const;
};

std::ostream &operator<<(std::ostream &o, const ShrubberyCreationForm &i);

#endif
