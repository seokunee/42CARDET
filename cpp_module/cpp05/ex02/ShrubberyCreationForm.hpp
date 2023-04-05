/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:24:38 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/05 16:46:16 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
	private:
		std::string _target;
	public:
		class CantOpenFile : public std::exception {
			public:
				const char* what() const throw();
		};
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		std::string getTarget() const;
		void	execute(Bureaucrat const & executor) const;
};

std::ostream &operator<<( std::ostream &o, const ShrubberyCreationForm &i );

#endif
