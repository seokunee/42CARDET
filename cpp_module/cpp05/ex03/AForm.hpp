/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:14:01 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/05 16:50:57 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		const int _grade_signed;
		const int _grade_execute ;
		bool	_signed;

		AForm();
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class ExecuteNotException : public std::exception {
			public:
				const char* what() const throw();
		};
		class SignedIsFalse : public std::exception {
			public:
				const char* what() const throw();
		};
		AForm(const std::string name, const int grade_signed, const int grade_excute);
		AForm(const AForm &src);
		~AForm();
		AForm &operator=(const AForm &src);

		std::string getName() const;
		int getGradeSigned() const;
		int getGradeExcute() const;
		bool getSigned() const;

		void	beSigned(const Bureaucrat &obj);
		virtual std::string getTarget() const = 0;
		virtual void	execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<( std::ostream &o, const AForm &i );

#endif
