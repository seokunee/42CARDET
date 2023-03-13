/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:56:40 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/13 20:35:33 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int	_fixPoint;
		static const int _bit = 8;

	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(int value);
		Fixed(float value);

		~Fixed();

		Fixed	&operator=(const Fixed &src);
		bool	operator==(const Fixed &src);
		bool	operator!=(const Fixed &src);
		bool	operator<(const Fixed &src);
		bool	operator>(const Fixed &src);
		bool	operator<=(const Fixed &src);
		bool	operator>=(const Fixed &src);

		Fixed	&operator+(const Fixed &src);
		Fixed	&operator-(const Fixed &src);
		Fixed	&operator*(const Fixed &src);
		Fixed	&operator/(const Fixed &src);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;


		static  Fixed	&min(Fixed &_fix1, Fixed &_fix2);
		static  Fixed	&max(Fixed &_fix1, Fixed &_fix2);
		static const Fixed	&min(const Fixed &_fix1, const Fixed &_fix2);
		static const Fixed	&max(const Fixed &_fix1, const Fixed &_fix2);
};

std::ostream &operator<<( std::ostream &o, Fixed const &i );

#endif
