/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:43:30 by seokchoi          #+#    #+#             */
/*   Updated: 2023/04/10 21:38:06 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib> // strtod
#include <cmath>   // isinf
#include <limits>  // numeric_limits.max , numeric_limits.min

class ScalarConverter
{
private:
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &src);
	~ScalarConverter();
	ScalarConverter &operator=(const ScalarConverter &src);

	static void convert(std::string literal);
};

#endif
