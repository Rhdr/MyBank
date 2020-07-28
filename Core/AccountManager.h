#pragma once
#include "Account.h"
#include "dbmanager.h"

class AccountManager : public Account
{
public:
	Account createAccount(int accNum, double bal);
	void updateAccount(int accNum);
	void deleteAccount(int accNum);
	std::string viewAccountInfo(int accNum);
	Account loadAccountInfo(int accNum);
private:
    DBManager dbmanager;
};

