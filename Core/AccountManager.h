#pragma once
#include "Account.h"
#include "dbmanager.h"

namespace Manager {
    class AccountManager
    {
    public:
        AccountManager();
        Account createAccount(double bal);
        bool addAcount(int usrId, Account& acc);
        bool updateAccount(Account& acc, double newValue);
        bool deleteAccount(Account& acc);
        bool isValid(Account& acc);
        Account loadAccountInfo(Account& acc);
    private:
        DBManager* dbmanager;
    };
}


