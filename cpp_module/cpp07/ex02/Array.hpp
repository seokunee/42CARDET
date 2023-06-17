/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:54 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/17 17:13:25 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _size;

public:
	Array() : _array(new T[0]), _size(0){};

	Array(unsigned int n) : _array(new T[n]), _size(n){};

	Array(const Array<T> &src) : _array(new T[src.size()]), _size(src.size())
	{
		if (this == &src)
			return;
		*this = src;
	};

	Array<T> &operator=(const Array<T> &src)
	{
		if (this == &src)
			return (*this);
		for (unsigned int i = 0; i < src.size(); i++)
		{
			_array[i] = src[i];
		}
		return (*this);
	}

	~Array()
	{
		if (_array != NULL)
			delete[] _array;
	};

	class OutOfBound : public std::exception
	{
	public:
		const char *what() const throw()
		{
			return ("Array index out of bound exception");
		};
	};

	T &operator[](unsigned int n)
	{
		if (n >= _size)
			throw(OutOfBound());
		return _array[n];
	};

	const T &operator[](unsigned int n) const
	{
		if (n >= _size)
			throw(OutOfBound());
		return _array[n];
	};

	unsigned int size() const
	{
		return _size;
	};
};

#endif
