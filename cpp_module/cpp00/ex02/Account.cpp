/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokchoi <seokchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 22:17:52 by seokchoi          #+#    #+#             */
/*   Updated: 2023/01/08 17:44:47 by seokchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

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

Account::Account (int initial_deposit){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_nbAccounts++;
}

Account::Account (void){
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account (void){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int	Account::checkAmount(void) const{
	return _amount;
}

void	Account::_displayTimestamp(void){
	time_t curTime = time(NULL);
	struct tm *pLocal = localtime(&curTime);

	std::cout << "[";
	std::cout << 1900 + pLocal->tm_year;
	if (pLocal->tm_mon + 1 < 10)
		std::cout << "0" << pLocal->tm_mon + 1;
	else
		std::cout << pLocal->tm_mon + 1;
	if (pLocal->tm_mday < 10)
		std::cout << "0" << pLocal->tm_mday;
	else
		std::cout << pLocal->tm_mday;
	std::cout << "_";
	if (pLocal->tm_hour < 10)
		std::cout << "0" << pLocal->tm_hour;
	else
		std::cout << pLocal->tm_hour;
	if (pLocal->tm_min < 10)
		std::cout << "0" << pLocal->tm_min;
	else
		std::cout << pLocal->tm_min;
	if (pLocal->tm_sec < 10)
		std::cout << "0" << pLocal->tm_sec;
	else
		std::cout << pLocal->tm_sec;
	std::cout << "] ";
}

void	Account::displayAccountsInfos(void){
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";";
	std::cout << "total:" << _totalAmount << ";";
	std::cout << "deposits:" << _totalNbDeposits << ";";
	std::cout << "withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void 	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit ){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}
