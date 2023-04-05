/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:30 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/05 16:50:41 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "AForm.hpp"
class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int	_grade;
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &src);

		const std::string getName() const;
		int	getGrade() const;

		void	increment();
		void	decrement();

		void	signForm(AForm &obj);
		void	executeForm(AForm const & form);
};

std::ostream &operator<<( std::ostream &o, const Bureaucrat &i );

#endif
