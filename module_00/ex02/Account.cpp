#include "Account.hpp"
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//getter
int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//member(?)function
void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ";" \
			<< "total:" << Account::getTotalAmount() << ";" \
			<< "deposits:" << Account::getNbDeposits() << ";" \
			<< "withdrawals:" << Account::getNbWithdrawals() \
			<< std::endl;
}

//copy constructer?
Account::Account( int initial_deposit )
{
	Account::_nbAccounts = _nbAccounts + 1;
	Account::_totalAmount = _totalAmount + initial_deposit;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;

	Account::_accountIndex = _nbAccounts - 1;
	Account::_amount = initial_deposit;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" \
			<< "amount:" << Account::_amount << ";" \
			<< "created" << std::endl;
}

//destructer
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" \
			<< "amount:" << Account::_amount << ";" \
			<< "closed" << std::endl;
	Account::_nbAccounts = 0;
	Account::_totalAmount = 0;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

//member(?)functions
void	Account::makeDeposit( int deposit )
{
	int	p_amount = Account::_amount;

	Account::_totalNbDeposits++;
	Account::_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_amount += deposit;
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" \
			<< "p_amount:" << p_amount << ";" \
			<< "deposit:" << deposit << ";" \
			<< "amount:" << Account::_amount << ";" \
			<< "nb_deposits:" << Account::_nbDeposits \
			<< std::endl;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" \
			<< "p_amount:" << Account::_amount << ";";
	if (Account::_amount - withdrawal < 0)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	Account::_totalNbWithdrawals++;
	Account::_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_amount -= withdrawal;
	std::cout << "withdrawal:" << withdrawal << ";" \
			<< "amount:" << Account::_amount << ";" \
			<< "nb_withdrawals:" << Account::_nbWithdrawals \
			<< std::endl;
	return (true);
}
int		Account::checkAmount( void ) const
{
	int	total_Amount = Account::getTotalAmount();
	return (total_Amount);
}
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";" \
			<< "amount:" << Account::_amount << ";" \
			<< "deposits:" << Account::_nbDeposits << ";" \
			<< "withdrawals:" << Account::_nbWithdrawals\
			<< std::endl;
}

void	Account::_displayTimestamp( void )
{	
	time_t	t = time(NULL);

	std::cout << "[" << std::put_time(localtime(&t), "%Y%m%d_%H%M%S") << "] ";
}

//constructer?
Account::Account( void )
{
	Account::_nbAccounts = 0;
	Account::_totalAmount = 0;
	Account::_totalNbDeposits = 0;
	Account::_totalNbWithdrawals = 0;

	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}
