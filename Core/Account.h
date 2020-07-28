#pragma once
#include <QString>

class Account
{
public:
    void setBalance(double bal);
    void setAccountNumber(int accNum);
    double getBalance() const;
    int getAccountNumber() const;
private:
    double balance;
    int accountNumber;
};

