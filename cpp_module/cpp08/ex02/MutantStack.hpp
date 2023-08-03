/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 03:14:10 by seokchoi          #+#    #+#             */
/*   Updated: 2023/07/23 18:10:14 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack(){};
	~MutantStack(){};
	MutantStack(const MutantStack &src)
	{
		*this = src;
	}

	MutantStack &operator=(const MutantStack &src)
	{
		if (this == &src)
			return *this;
		this->c = src.c;
		return *this;
	}

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;
	typedef typename MutantStack<T>::stack::container_type::const_iterator const_iterator;
	typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
	typedef typename MutantStack<T>::stack::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }

	const_iterator begin() const { return this->c.begin(); }
	const_iterator end() const { return this->c.end(); }

	reverse_iterator rbegin() { return this->c.rbegin(); }
	reverse_iterator rend() { return this->c.rend(); }

	const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif
