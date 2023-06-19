/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 03:14:10 by seokchoi          #+#    #+#             */
/*   Updated: 2023/06/19 18:20:34 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// private:
// 	typename T _mutantStack;

// public:
// 	void push(typename T::value_type i)
// 	{
// 		_mutantStack.push(i);
// 	};

// 	void pop()
// 	{
// 		_mutantStack.pop();
// 	};

// 	typename T::iterator begin(){

// 	};
// 	typename T::iterator end(){

// 	};
// };

// template <typename T>
// class MutantStack : public std::stack<T>
// {
// public:
// 	typename Container::iterator begin() { return this->c.begin(); }
// 	typename Container::iterator end() { return this->c.end(); }
// };

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	using typename std::stack<T, Container>::container_type;
	using typename container_type::iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#endif
