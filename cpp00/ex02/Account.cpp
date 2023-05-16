/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:14 by emajuri           #+#    #+#             */
/*   Updated: 2023/05/16 18:19:15 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "created\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "closed\n";
}

void Account::_displayTimestamp() {
	std::cout << "[Time] ";
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
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" + std::to_string(_accountIndex) + ";";
	std::cout << "p_amount:" + std::to_string(_amount) + ";";
	std::cout << "deposit:" + std::to_string(deposit) + ";";
	_amount += deposit;
	_nbDeposits++;
	std::cout << "amount:" + std::to_string(_amount) + ";";
	std::cout << "nb_deposits:" + std::to_string(_nbDeposits) + "\n";
	_totalNbDeposits++;
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
		std::cout << "amount:" + std::to_string(_amount) + ";";
		std::cout << "nb_withdrawals:" + std::to_string(_nbWithdrawals) + "\n";
		_totalNbWithdrawals++;
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
