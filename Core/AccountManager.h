#pragma once
#include "Account.h"
#include "dbmanager.h"

class AccountManager
{
public:
    AccountManager();
    Account createAccount(double bal);
    bool addAcount(int usrId,Account& acc);
    bool updateAccount(int accNum);
    bool deleteAccount(int accNum);
	Account loadAccountInfo(int accNum);
private:
    DBManager* dbmanager;
};

