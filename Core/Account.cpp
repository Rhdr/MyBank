#include "Account.h"

Account::Account(){}

Account::Account(double bal)
{
    balance = bal;
}

void Account::setBalance(double bal)
{
    balance = bal;
}

void Account::setAccountNumber(int accNum)
{
    accountNumber = accNum;
}

double Account::getBalance() const
{
    return balance;
}

int Account::getAccountNumber() const
{
    return accountNumber;
}
