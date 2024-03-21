#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void)
{
    return Account::_totalAmount;
}

int Account::getNbDeposits(void)
{
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return Account::_totalNbWithdrawals;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    if (Account::_amount > withdrawal)
        return true;
    return false;
}

int		Account::checkAmount( void ) const
{
    return ((Account::_amount));
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "account:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << Account::_nbAccounts << ";";
    std::cout << "amount:" << Account::_amount << ";";
    _nbAccounts < 8 ? std::cout << "" : std::cout << "deposits:" << Account::_nbDeposits << ";";
    _nbAccounts < 8 ? std::cout << "" : std::cout << "withdrawals:" << Account::getNbWithdrawals() << ";";
    if (_nbAccounts < 8)
        std::cout << "created";
    std::cout << std::endl;
}


void Account::makeDeposit(int deposit)
{
    Account::_amount += deposit;
    Account::_totalAmount += deposit;
}
/*Constructeur*/
Account::Account( int initial_deposit )
{
    Account::_nbAccounts++;
    Account::_amount += initial_deposit;
    Account::_totalAmount += initial_deposit;
    displayStatus();
}

/*Desctructeur*/
Account::~Account( void )
{
    Account::_nbAccounts--;
    std::cout << "closed" << std::endl;
}


void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout << "[" << buffer << "] ";
}

