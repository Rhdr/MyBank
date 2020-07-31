#include "AccountManager.h"
#include <QDebug>

using namespace Manager;

AccountManager::AccountManager()
{
    dbmanager = DBManager::getInstance();
}

Account AccountManager::createAccount(double bal)
{
    return Account(bal);
}

bool AccountManager::addAcount(int usrId, Account& acc)
{
    bool status = false;
    int accountNumber = acc.getAccountNumber();
    if(!dbmanager->AccountExits(accountNumber)){
        double accountBalance = acc.getBalance();
        if(dbmanager->insertAccount(usrId, accountBalance)){
            qDebug() << "Account inserted";
            status = true;
        }else{
            qDebug() << "Account not Inserted";
            status = false;
        }
    }else{
        qDebug() << "Account already exists";
    }
    return status;
}

bool AccountManager::updateAccount(int accNum, double newValue)
{
    bool status = false;
    if(dbmanager->AccountExits(accNum)){
        if(dbmanager->updateAccount(accNum, newValue)){
            qDebug() << "Account updated";
            status = true;
        }else{
            qDebug() << "Account not updated";
            status = false;
        }
    }else{
        qDebug() << "Account not found";
    }
    return status;
}

bool AccountManager::deleteAccount(int accNum)
{
    bool status = false;
    if(dbmanager->AccountExits(accNum)){

        if(dbmanager->deleteAccount(accNum)){
            qDebug() << "Account deleted";
            status = true;
        }else{
            qDebug() << "Account not deleted";
            status = false;
        }
    }else{
        qDebug() << "Account not found";
    }
    return status;

}

bool AccountManager::isValid(int accNum)
{
    bool status = false;
    if(dbmanager->AccountExits(accNum))
        status = true;
    return status;
}

Account AccountManager::loadAccountInfo(int accNum) //might need to add user id for retriving an AccountList
{
    if(dbmanager->AccountExits(accNum)){
        QList<QVariant> list = dbmanager->getAccountData(accNum);
        if(list.isEmpty()){
            qDebug() << "failed to fetch data from database";
            return Account();
        }else{
            Account acc = this->createAccount(list.at(1).toDouble());
            acc.setAccountNumber(list[0].toInt());
            return acc;
        }
    }else{
        qDebug() << "User not found";
        return Account();
    }
}
