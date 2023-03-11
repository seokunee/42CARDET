/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:56:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/11 21:47:49 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_fixPoint; // 10 * 2^8 +   = 101010000000
		static const int _bit = 8;
		// 4byte -> 32bit => 1bit 31 - 8 정수 , 8 소수
	// 10.5 => 1010.10000000
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(int value);
		Fixed(float value);
		Fixed &operator=(const Fixed &src);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<( std::ostream &o, Fixed const &i );

#endif
