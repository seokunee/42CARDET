/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:03:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/15 20:42:04 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	// Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed a(8388608);
	int k = -2147483647;
	std::cout << ((k << 8) >>8) << std::endl;
	std::cout << static_cast<int>(-42.42f) <<std::endl;
	std::cout << (a.getRawBits()) << std::endl;
	std::cout << a.toInt() << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	// std::cout << Fixed::min( a, b ) << std::endl;

	// std::cout << "-------test-------" << std::endl;

	// bool	value;

	// value = a < b;
	// std::cout << value << std::endl;

	// value = a > b;
	// std::cout << value << std::endl;

	// value = a <= b;
	// std::cout << value << std::endl;

	// value = a >= b;
	// std::cout << value << std::endl;

	// value = a == b;
	// std::cout << value << std::endl;

	// value = a != b;
	// std::cout << value << std::endl;

	// std::cout << a + b << std::endl;
	// std::cout << a - b << std::endl;
	// std::cout << a * b << std::endl;
	// std::cout << a / b << std::endl;
	return 0;
}
