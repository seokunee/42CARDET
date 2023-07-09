/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:22:54 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/09 20:01:21 by seokchoi         ###   ########.fr       */
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
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = src[i];
		}
	};

	Array<T> &operator=(const Array<T> &src)
	{
		if (this == &src)
			return (*this);
		delete[] _array;
		_size = src.size();
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_array[i] = src._array[i];
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

	T &operator[](const unsigned int n)
	{
		if (n >= _size)
			throw(OutOfBound());
		return _array[n];
	};

	const T &operator[](const unsigned int n) const
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
