/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:03:28 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/17 23:29:32 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

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



// #include <bitset>
// #include "cmath"
// void expainbit()
// {
// 	float f_value = 8388608.0f;
// 	int i_value = -8388609 ;

// 	/*
// 	* float
// 	*/
// 	std::cout << "-------------float-------------" << std::endl;
// 	unsigned int ui = *reinterpret_cast<unsigned int*>(&f_value);
// 	std::bitset<32> bit5(ui);
// 	std::cout << bit5 << std::endl;
// 	std::cout << "f_value : " << f_value << std::endl;

// 	float left_shift_f_value = roundf(f_value * static_cast<float>(1 << 8));
// 	ui = *reinterpret_cast<unsigned int*>(&left_shift_f_value);
// 	std::bitset<32> bit1(ui);
// 	std::cout << bit1 << std::endl;
// 	std::cout << "left_shift_f_value : " << left_shift_f_value << std::endl;

// 	int fixPoint = left_shift_f_value;
// 	std::bitset<32> bit2(fixPoint);
// 	std::cout << bit2 << std::endl;
// 	std::cout << "fixPoint : " << fixPoint << std::endl;
	
// 	int toInt = fixPoint / 256;
// 	std::bitset<32> bit3(toInt);
// 	std::cout << bit3 << std::endl;
// 	std::cout << "toInt : " << toInt << std::endl;

// 	float toFloat = fixPoint / static_cast<float>(1 << 8);
// 	std::bitset<32> bit4(toFloat);
// 	std::cout << bit4 << std::endl;
// 	std::cout << "toFloat : " << toFloat << std::endl;

// 	/*
// 	* int
// 	*/
// 	std::cout << "-----------------------------" << std::endl;
// 	std::cout << "-------------int-------------" << std::endl;
// 	std::bitset<32> bit6(i_value);
// 	std::cout << bit6 << std::endl;
// 	std::cout << "i_value : " << i_value << std::endl;

// 	int left_shift_i_value = i_value << 8;
// 	std::bitset<32> bit7(left_shift_i_value);
// 	std::cout << bit7 << std::endl;
// 	std::cout << "left_shift_i_value : " << left_shift_i_value << std::endl;

// 	fixPoint = left_shift_i_value; // int
// 	std::bitset<32> bit8(fixPoint);
// 	std::cout << bit8 << std::endl;
// 	std::cout << "fixPoint : " << fixPoint << std::endl;
	
// 	toInt = fixPoint / 256;
// 	std::bitset<32> bit9(toInt);
// 	std::cout << bit9 << std::endl;
// 	std::cout << "toInt : " << toInt << std::endl;

// 	toFloat = fixPoint / static_cast<float>(1 << 8);
// 	std::bitset<32> bit10(toFloat);
// 	std::cout << bit10 << std::endl;
// 	std::cout << "toFloat : " << toFloat << std::endl;
// 	std::cout << "-----------------------------" << std::endl;
// }