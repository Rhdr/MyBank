#include "Account.h"

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
