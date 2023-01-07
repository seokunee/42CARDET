/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:17:52 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/06 16:13:40 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::getNbAccounts(){
	return _nbAccounts;
}

int Account::getTotalAmount(){
	return _totalAmount;
}

int Account::getNbDeposits(){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(){
	return _totalNbWithdrawals;
}

Account::Account (int initial_deposit) {
	_accountIndex = 0;
	_amount = 0;
	_nbDeposits = initial_deposit;
	_nbWithdrawals = 0;
}

Account::Account (void) {
	_accountIndex = _nbAccounts;
	_nbAccounts += 1;
}

void	Account::_displayTimestamp(void){
	time_t curTime = time(NULL);
	struct tm *pLocal = localtime(&curTime);
	
	std::cout.fill(0);
	std::cout << "[";
	std::cout << 1900 + pLocal->tm_year;
	std::cout << pLocal->tm_mon << pLocal->tm_mday << "_";
	std::cout << pLocal->tm_hour << pLocal->tm_min << pLocal->tm_sec;
	std::cout << " ";
}

void	Account::displayAccountsInfos(void){
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _nbAccounts << ";";
	std::cout << "withdrawals:" << _totalNbDeposits << ";";
	std::cout << std::endl;
}

void 	Account::displayStatus(void) const {
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << ";";
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount = _amount + deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << ";";
	std::cout << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal ){
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "index:" << _accountIndex << ";";

}
