/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:30 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/06 18:27:11 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
	private:
		char 	_c;
		int 	_i;
		float 	_f;
		double 	_d;
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &src);

		static void convert(std::string literal);
};

#endif
