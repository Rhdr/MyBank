#include "UserManager.h"
#include <QDebug>

UserManager::UserManager(){}

User UserManager::createUser(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd)
{
    return User(fnam, lnam, eml, usrnam, psswrd);
}

bool UserManager::addUser(User& usr)
{
    bool status = false;
    if(!dbmanager.UserExits(usr.getUserName(), usr.getPassWord())){
        if(dbmanager.insertUser(usr)){
            qDebug() << "User inserted";
            status = true;
        }else{
            qDebug() << "User not Inserted";
            status = false;
        }
    }else{
        qDebug() << "User already exists";
    }
    return status;
}

bool UserManager::updateUser(User& usr, int flag, QVariant value)
{
    bool status = false;
    if(dbmanager.UserExits(usr.getUserName(), usr.getPassWord())){
        if(dbmanager.updateUser(usr, flag, value)){
            qDebug() << "User updated";
            status = true;
        }else{
            qDebug() << "User not updated";
            status = false;
        }
    }else{
        qDebug() << "User not found";
    }
    return status;
}

bool UserManager::deleteUser(User& usr)
{
    bool status = false;
    if(dbmanager.UserExits(usr.getUserName(), usr.getPassWord())){
        if(dbmanager.deleteUser(usr)){
            qDebug() << "User deleted";
            status = true;
        }else{
            qDebug() << "User not deleted";
            status = false;
        }
    }else{
        qDebug() << "User not found";
    }
    return status;

}

bool UserManager::validateUser(QString usrnam, QString psswrd)
{
    bool status = false;
    if(dbmanager.UserExits(usrnam, psswrd))
        status = true;
    return status;
}

User UserManager::loadUserData(QString usrnam, QString psswrd)
{
    if(dbmanager.UserExits(usrnam, psswrd)){
        QList<QVariant> list = dbmanager.getUserData(usrnam,psswrd);
        if(list.isEmpty()){
            qDebug() << "failed to fetch data from database";
            return User();
        }else{
            return this->createUser(list[0].toString(), list[1].toString(), list[2].toString(),
                list[3].toString(), list[4].toString());
        }
    }else{
        qDebug() << "User not found";
        return User();
    }

}

