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
    if (Account::_amount < withdrawal)
    {
        _displayTimestamp();
        std::cout << "index:" << _accountIndex << ";";
        std::cout << "p_amount:" << Account::_amount << ";";
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    Account::_nbWithdrawals = withdrawal;
    Account::_totalNbWithdrawals++;
    displayStatus();
    _nbWithdrawals = 1;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return Account::_amount;
}

void	Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus( void ) const
{
     _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    if (Account::_nbDeposits > 1)
    {
        std::cout << "p_amount:" <<  Account::_amount - _nbDeposits << ";";
        std::cout << "deposit:" << _nbDeposits << ";";
        std::cout << "amount:" << Account::_amount << ";";
        std::cout << "nb_deposits:1" << std::endl;
        return ;
    }
    else if (Account::_nbWithdrawals > 1)
    {
        std::cout << "p_amount:" <<  Account::_amount + _nbWithdrawals << ";";
        std::cout << "withdrawal:" << _nbWithdrawals << ";";
        std::cout << "amount:" << Account::_amount << ";";
        std::cout << "nb_withdrawals:1" << std::endl;
        return ;
    }
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{

    Account::_nbDeposits = deposit;
    Account::_amount += deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    displayStatus();
    _nbDeposits = 1;
}

/*Constructeur*/
Account::Account( int initial_deposit )
{
    Account::_amount = initial_deposit;
    Account::_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_totalNbDeposits = 0;
    Account::_totalNbWithdrawals = 0;
    Account::_nbDeposits = 0;
    Account::_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "created" << std::endl;
}

/*Desctructeur*/
Account::~Account( void )
{
    Account::_nbAccounts--;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << Account::_amount << ";";
    std::cout << "closed" << std::endl;
}


void Account::_displayTimestamp(void)
{
    std::time_t now = std::time(nullptr);
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", std::localtime(&now));
    std::cout << "[" << buffer << "] ";
}

