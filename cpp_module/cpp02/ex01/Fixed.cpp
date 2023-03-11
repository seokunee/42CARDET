/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:56:27 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/11 21:47:48 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixPoint = 0;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
};

Fixed::Fixed(int value){
	std::cout << "Int constructor called" << std::endl;
	_fixPoint = value << _bit;
};

Fixed::Fixed(float value){
	std::cout << "Float constructor called" << std::endl;
	_fixPoint = roundf(value * static_cast<int>(1 << _bit));
};

Fixed &Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixPoint = src.getRawBits();
	return (*this);
};

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixPoint);
};

void Fixed::setRawBits( int const raw ){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixPoint = raw;
};

float Fixed::toFloat( void ) const{
	return (_fixPoint );
};

int Fixed::toInt( void ) const{
	return (_fixPoint >> _bit);
};

std::ostream &operator<<( std::ostream &o, Fixed const &fix ){
	std::cout <<
};

