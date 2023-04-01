/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:14:01 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/01 03:29:55 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
	private:
		const std::string _name;
		const int _grade_signed;
		const int _grade_execute;
		bool	_signed;

	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		
		Form();
		Form(const std::string name, const int grade_signed, const int grade_excute);
		Form(const Form &src);
		~Form();
		Form &operator=(const Form &src);

		std::string getName() const;
		int getGradeSigned() const;
		int getGradeExcute() const;
		bool getSigned() const;

		void	beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<( std::ostream &o, const Form &i );

#endif