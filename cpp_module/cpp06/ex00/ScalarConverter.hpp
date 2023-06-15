/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:30 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/16 00:37:53 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib> // strtod
#include <cmath>   // isinf
#include <limits>  // numeric_limits.max , numeric_limits.min
#include <sstream>

class ScalarConverter
{
private:
	static void changeChar(std::string &literal);
	static void changeInt(std::string &literal);
	static void changeFloat(std::string &literal);
	static void changeDouble(std::string &literal);
	static bool checkDoublePoint(double d);
	static bool checkFloatPoint(float f);

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string literal);
};

#endif
