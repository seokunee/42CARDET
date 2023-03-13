/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:56:27 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/13 20:48:13 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "cmath"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixPoint = 0;
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
	_fixPoint = roundf(value * static_cast<float>(1 << _bit));
};

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixPoint);
};

void Fixed::setRawBits( int const raw ){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixPoint = raw;
};

float Fixed::toFloat( void ) const{
	return (_fixPoint / static_cast<float>(1 << _bit));
};

int Fixed::toInt( void ) const{
	return (_fixPoint >> _bit);
};

Fixed &Fixed::operator=(const Fixed &src){
	std::cout << "Copy assignment operator called" << std::endl;
	_fixPoint = src.getRawBits();
	return (*this);
};

bool	Fixed::operator==(const Fixed &src){
	if (_fixPoint == src._fixPoint)
		return (true);
	return (false);
};

bool	Fixed::operator!=(const Fixed &src){
	if (_fixPoint != src._fixPoint)
		return (true);
	return (false);
};

bool	Fixed::operator<(const Fixed &src){
	if (_fixPoint < src._fixPoint)
		return (true);
	return (false);
};

bool	Fixed::operator>(const Fixed &src){
	if (_fixPoint > src._fixPoint)
		return (true);
	return (false);
};

bool	Fixed::operator<=(const Fixed &src){
	if (_fixPoint <= src._fixPoint)
		return (true);
	return (false);
};

bool	Fixed::operator>=(const Fixed &src){
	if (_fixPoint >= src._fixPoint)
		return (true);
	return (false);
};

Fixed &Fixed::operator+(const Fixed &src){

};

Fixed &Fixed::operator-(const Fixed &src){

};

Fixed &Fixed::operator*(const Fixed &src){

};

Fixed &Fixed::operator/(const Fixed &src){

};

static  Fixed	&min(Fixed &_fix1, Fixed &_fix2){

};

static  Fixed	&max(Fixed &_fix1, Fixed &_fix2){

};

static const Fixed	&min(const Fixed &_fix1, const Fixed &_fix2){

};

static const Fixed	&max(const Fixed &_fix1, const Fixed &_fix2){

};


std::ostream &operator<<( std::ostream &o, Fixed const &fix ){
	o << fix.toFloat();
	return o;
};
