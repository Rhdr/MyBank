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
    if(!dbmanager->AccountExits(acc)){
        if(dbmanager->insertAccount(usrId, acc)){
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

bool AccountManager::updateAccount(Account& acc, double newValue)
{
    bool status = false;
    if(dbmanager->AccountExits(acc)){
        if(dbmanager->updateAccount(acc, newValue)){
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

bool AccountManager::deleteAccount(Account &acc)
{
    bool status = false;
    if(dbmanager->AccountExits(acc)){
        if(dbmanager->deleteAccount(acc)){
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

bool AccountManager::isValid(Account &acc)
{
    bool status = false;
    if(dbmanager->AccountExits(acc))
        status = true;
    return status;
}

Account AccountManager::loadAccountInfo(Account &acc)
{
    if(dbmanager->AccountExits(acc)){
        QList<QVariant> list = dbmanager->getAccountData(acc);
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
