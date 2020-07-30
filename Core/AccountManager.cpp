#include "AccountManager.h"
#include <QDebug>

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

