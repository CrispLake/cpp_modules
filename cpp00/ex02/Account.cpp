/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/16 19:22:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "closed\n";
	_nbAccounts--;
	_totalAmount -= _amount;
}

void Account::_displayTimestamp() {
	time_t t = time(NULL);
	tm *l = std::localtime(&t);
	std::cout << "[";
	std::cout << l->tm_year + 1900;
	if (l->tm_mon < 10)
		std::cout << '0';
	std::cout << l->tm_mon;
	if (l->tm_mday < 10)
		std::cout << '0';
	std::cout << l->tm_mday << '_';
	if (l->tm_hour < 10)
		std::cout << '0';
	std::cout << l->tm_hour;
	if (l->tm_min < 10)
		std::cout << '0';
	std::cout << l->tm_min;
	if (l->tm_sec < 10)
		std::cout << '0';
	std::cout << l->tm_sec;
	std::cout << "] ";
}

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" + std::to_string(_nbAccounts) + ";";
	std::cout << "total:" + std::to_string(_totalAmount) + ";";
	std::cout << "deposits:" + std::to_string(_totalNbDeposits) + ";";
	std::cout << "withdrawals:" + std::to_string(_totalNbWithdrawals) + "\n";
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "p_amount:" + std::to_string(_amount) + ";";
	std::cout << "deposit:" + std::to_string(deposit) + ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "nb_deposits:" + std::to_string(_nbDeposits) + "\n";
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "p_amount:" + std::to_string(_amount) + ";";
	if (_amount >= withdrawal)
	{
		std::cout << "withdrawal:" + std::to_string(withdrawal) + ";";
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout << "amount:" + std::to_string(_amount) + ";";
		std::cout << "nb_withdrawals:" + std::to_string(_nbWithdrawals) + "\n";
		return (true);
	}
	std::cout << "withdrawal:refused\n";
	return (false);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
}
