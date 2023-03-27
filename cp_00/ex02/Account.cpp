#include "Account.hpp"
#include <iostream>
#include <cctype>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <string> 


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {return _nbAccounts;};
int	Account::getTotalAmount( void ){return _totalAmount;};
int	Account::getNbDeposits( void ){return _totalNbDeposits;};
int	Account::getNbWithdrawals( void ){return _totalNbWithdrawals;};

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts();
    std::cout << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits();
    std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
};

void	Account::_displayTimestamp( void )
{
  // Get current time
  std::time_t now = std::time(0);
  std::tm* tm_ptr = std::localtime(&now);

  // Format date and time string
  char datetime_str[20];
  std::strftime(datetime_str, sizeof(datetime_str), "%Y%m%d_%H%M%S", tm_ptr);

  // Output string to console
  std::cout << '[' << datetime_str << "] ";
}

Account::Account( int initial_deposit )
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
	_totalNbDeposits++;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<  ";p_amount:" << _amount;
    if(_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return(0);
    }
	_amount -= withdrawal;
    _totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (1);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex;
    std::cout << ";amount:" << _amount;
    std::cout << ";deposits:" << _nbDeposits;
    std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}