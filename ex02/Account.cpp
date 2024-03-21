#include "Account.hpp"

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "account:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    if (_amount > withdrawal)
        return true;
    return false;
}

int		Account::checkAmount( void ) const
{
    return ((_amount));
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "account:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_amount += deposit;
    Account::_totalAmount += deposit;
}

Account::~Account( void )
{
    _nbAccounts--;
    std::cout << "closed" << std::endl;
}

Account::Account( int initial_deposit )
{
    _nbAccounts++;
    _amount += initial_deposit;
}

void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout << "[" << buffer << "]" << std::endl;
}

