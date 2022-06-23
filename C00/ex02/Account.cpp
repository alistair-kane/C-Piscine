/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:53:04 by alkane            #+#    #+#             */
/*   Updated: 2022/06/23 21:32:05 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include "ctime"
#include "iostream"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : 
	_accountIndex(_nbAccounts),
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout 
		<< "index:"
		<< _accountIndex 
		<< ";amount:" 
		<< _amount 
		<< ";created"
		<< std::endl;
	_nbAccounts++;
	_totalAmount += _amount;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout 
		<< "index:"
		<< _accountIndex 
		<< ";amount:" 
		<< _amount 
		<< ";closed"
		<< std::endl;
}

void    Account::_displayTimestamp(void)
{
	std::time_t	now = time(0);
	std::tm		*ltm = localtime(&now);
	
	std::cout 
		<< "[" 
		<< 1900 + ltm->tm_year 
		<< '0' 
		<< 1 + ltm->tm_mon 
		<< ltm->tm_mday 
		<< '_';
	if (ltm->tm_hour < 10)
		std::cout << '0';
	std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << '0';
	std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << '0';
	std::cout << ltm->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" 
		<< _nbAccounts 
		<< ";total:"
		<< _totalAmount
		<< ";deposits:"
		<< _totalNbDeposits
		<< ";withdrawls:"
		<< _totalNbWithdrawals
		<< std::endl;
}

void    Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";amount:"
		<< _amount
		<< ";deposits:"
		<< _nbDeposits
		<< ";withdrawals:"
		<< _nbWithdrawals
		<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits += 1;
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";deposit:"
		<< deposit
		<< ";amount:"
		<< (_amount + deposit)
		<< ";nb_deposits:"
		<< _nbDeposits
		<< std::endl;
	_amount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:"
		<< _accountIndex
		<< ";p_amount:"
		<< _amount
		<< ";withdrawal:";
	if (_amount - withdrawal > 0)
	{
		std::cout << withdrawal;
		_amount -= withdrawal;
		_nbWithdrawals += 1;
		std::cout
			<< ";amount:"
			<< _amount
			<< ";nb_withdrawals:"
			<< _nbWithdrawals
			<< std::endl;
		return (true);
	}
	std::cout << "refused" << std::endl;
	return (false);
}