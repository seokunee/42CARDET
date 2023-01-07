/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:08:06 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/03 19:35:36 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	// vector를 하면 동적할당이 된다.
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
	// pair은 유사한 데이터를 묶어주는 클래스이다.
	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	// 생성자가 시작하는 동시에 created라는 문구를 띄운다.
	// 동적할당할 크기만큼 컨테이너를 생성해준다.
	accounts_t::iterator	acc_begin	= accounts.begin();
	// vector는 컨테이너, 이터레이터, 알고리즘 템플릿을 제공한다.
	// 컨테이너란 배열과 비슷한 것인데 여러 메서드가 존재해서 컨테이너를 편집하고 활용하기가  좋다.
	// 이터레이터란 반복문을 할 수 있게 해주는 것인데 배열을 손쉽게 반복으로 사용할 수 있다. 
	// 알고리즘은 뭐 아직은 모르겠다잉
	accounts_t::iterator	acc_end		= accounts.end();
	// accounts.end를 하면 컨테이너의 마지막 요소를 얻을 수 있다.
	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos(); // created 부분
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );
	// for_each는 반복문으로 acc_begin 부터 acc_end까지 displayStatus 함수를 실행시킨다.
	for ( acc_int_t it( acc_begin, dep_begin );
		it.first != acc_end && it.second != dep_end;
		++(it.first), ++(it.second) ) {
			// pair클래스 타입을 가지는 acc_int_t it을 생성하였고
			// it.first는 acc를 it.second는 dep를 가르킨다.
			// ++ 로 순서를 넘겨준다.
		(*(it.first)).makeDeposit( *(it.second) );
		// deposit을 바꾸면 로그를 띄움
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		it.first != acc_end && it.second != wit_end;
		++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
		// withdrawal을 바꾸면 로그를 띄운다.
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //