#include "UserManager.h"
#include <QDebug>

using namespace Manager;

UserManager::UserManager(){
    dbmanager = DBManager::getInstance();
}

User UserManager::createUser(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd)
{
    return User(fnam, lnam, eml, usrnam, psswrd);
}

bool UserManager::addUser(User& usr)
{
    bool status = false;
    auto fnam = usr.getFirstName();
    auto lnam = usr.getLastName();
    auto eml = usr.getEmail();
    auto usrnam = usr.getUserName();
    auto psswrd = usr.getPassWord();

    if(!dbmanager->UserExits(usrnam, psswrd)){
        if(dbmanager->insertUser(fnam, lnam, eml, usrnam, psswrd)){
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
    auto current_usrnam = usr.getUserName();
    auto current_psswrd = usr.getPassWord();
    QList<QString> fieldlist = {"First_Name", "Last_Name", "Email", "Username", "Password"};
    QString field = fieldlist.at(flag);
    QString new_value = "";

    if(field == "First_Name") {
        usr.setFirstName(value.toString());
        new_value = usr.getFirstName();
    }else if (field == "Last_Name") {
        usr.setLastName(value.toString());
        new_value = usr.getLastName();
    }else if (field == "Email") {
        usr.setEmail(value.toString());
        new_value = usr.getEmail();
    }else if (field == "Username") {
        usr.setUserName(value.toString());
        new_value = usr.getUserName();
    }else if (field == "Password") {
        usr.setPassWord(value.toString());
        new_value = usr.getPassWord();
    }else{
        qDebug() << "invalid option";
    }

    if(dbmanager->UserExits(current_usrnam, current_psswrd)){

        if(dbmanager->updateUser(current_usrnam, current_psswrd, field, new_value)){
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
    auto usrnam = usr.getUserName();
    auto psswrd = usr.getPassWord();
    if(dbmanager->UserExits(usr.getUserName(), usr.getPassWord())){
        if(dbmanager->deleteUser(usrnam, psswrd)){
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

bool UserManager::validateUser(User& usr)
{
    bool status = false;
    auto usrnam = usr.getUserName();
    auto psswrd = usr.getPassWord();
    if(dbmanager->UserExits(usrnam, psswrd))
        status = true;
    return status;
}

User UserManager::loadUserData(User &usr)
{
    auto usrnam = usr.getUserName();
    auto psswrd = usr.getPassWord();
    if(dbmanager->UserExits(usrnam, psswrd)){
        QList<QVariant> list = dbmanager->getUserData(usrnam, psswrd);
        if(list.isEmpty()){
            qDebug() << "failed to fetch data from database";
            return User();
        }else{
            User usr = this->createUser(list[1].toString(), list[2].toString(), list[3].toString(),
                list[4].toString(), list[5].toString());
            usr.setUserId(list[0].toInt());
            return usr;
        }
    }else{
        qDebug() << "User not found";
        return User();
    }
}

