/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:56:27 by seokchoi          #+#    #+#             */
/*   Updated: 2023/03/17 23:29:49 by seokchoi         ###   ########.fr       */
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
	_fixPoint = value * (1 << _bit);
};

Fixed::Fixed(float value){
	std::cout << "Float constructor called" << std::endl;
	// std::cout << "test " << roundf(value * static_cast<float>(1 << _bit)) << std::endl;

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
	std::cout << "fixPoint = " << _fixPoint << std::endl;
	return (_fixPoint / (1 << _bit));
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

Fixed Fixed::operator+(const Fixed &src){
	Fixed newFix(this->toFloat() + src.toFloat());
	return (newFix);
};

Fixed Fixed::operator-(const Fixed &src){
	Fixed newFix(this->toFloat() - src.toFloat());
	return (newFix);
};

Fixed Fixed::operator*(const Fixed &src){
	Fixed newFix(this->toFloat() * src.toFloat());
	return (newFix);
};

Fixed Fixed::operator/(const Fixed &src){
	Fixed newFix(this->toFloat() / src.toFloat());
	return (newFix);
};

Fixed &Fixed::min(Fixed &fix1, Fixed &fix2){
	if (fix1.getRawBits() <= fix2.getRawBits())
		return (fix1);
	return (fix2);
};

Fixed &Fixed::operator++(){
	this->_fixPoint = this->_fixPoint + 1;
	return (*this);
};

Fixed Fixed::operator++(int){
	Fixed tmp(*this);
	this->_fixPoint = this->_fixPoint + 1;
	return (tmp);
};

Fixed &Fixed::operator--(){
	this->_fixPoint = this->_fixPoint - 1;
	return (*this);
};

Fixed Fixed::operator--(int){
	Fixed tmp(*this);
	this->_fixPoint = this->_fixPoint - 1;
	return (tmp);
};

Fixed &Fixed::max(Fixed &fix1, Fixed &fix2){
	if (fix1.getRawBits() >= fix2.getRawBits())
		return (fix1);
	return (fix2);
};

const Fixed &Fixed::min(const Fixed &fix1, const Fixed &fix2){
	if (fix1.getRawBits() <= fix2.getRawBits())
		return (fix1);
	return (fix2);
};

const Fixed &Fixed::max(const Fixed &fix1, const Fixed &fix2){
	if (fix1.getRawBits() >= fix2.getRawBits())
		return (fix1);
	return (fix2);
};

std::ostream &operator<<( std::ostream &o, Fixed const &fix ){
	o << fix.toFloat();
	return o;
};
