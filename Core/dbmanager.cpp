#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlDatabase>
#include <QDebug>
#include "dbmanager.h"
#include "dbsettings.h"

using namespace Manager;

#ifndef DB_LAST_SAVED //TODO : Add a guard for when DB_LAST_SAVED is not defined
#define DB_LAST_SAVED QSqlDatabase AppDatabase = Settings::DBsettings::lastSaved();
#endif

DBManager* DBManager::dbManagerInstance = nullptr;

DBManager* DBManager::getInstance(){

    if(dbManagerInstance == nullptr){
        dbManagerInstance = new DBManager();
    }
    return dbManagerInstance;
}

DBManager::DBManager()
{
    QSqlDatabase AppDatabase = QSqlDatabase::addDatabase("QSQLITE");
    AppDatabase.setDatabaseName("MyBankDB.db");

    if (!AppDatabase.open()){
        qDebug() << "DATABASE:: Failed to connect to database - " << AppDatabase.lastError();
    }else{
        qDebug() << "DATABASE:: Connection successful";
    }

    Settings::DBsettings::save(AppDatabase);
}

DBManager::~DBManager()
{
    DB_LAST_SAVED
    delete dbManagerInstance;
    AppDatabase.close();
    QSqlDatabase::removeDatabase(AppDatabase.databaseName());
    qDebug() << "DATABASE:: Database closed";
}

bool DBManager::isOpen() const
{
    return Settings::DBsettings::lastSaved().open();
}

//Users Table
bool DBManager::insertUser(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;
    query.prepare("INSERT INTO Users(First_Name, Last_Name, Email, Username, Password)"
                  "VALUES (:First_Name, :Last_Name, :Email, :Username, :Password)");
    query.bindValue(":First_Name", fnam);
    query.bindValue(":Last_Name", lnam);
    query.bindValue(":Email", eml);
    query.bindValue(":Username", usrnam);
    query.bindValue(":Password", psswrd);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record insert successful";
        }else{
            qDebug() << "DATABASE:: Record insert unsuccessful - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::deleteUser(QString usrnam, QString psswrd)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;
    query.prepare("DELETE FROM Users WHERE Username = :Username AND Password = :Password");
    query.bindValue(":Username", usrnam);
    query.bindValue(":Password", psswrd);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record deleted successfully";
        }else{
            qDebug() << "DATABASE:: Record deletion failed - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::updateUser(QString usrnam, QString psswrd, QString field, QString& value)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;

    query.prepare("UPDATE Users SET " + field + " = :newValue WHERE Username = :Username AND Password = :Password");
    query.bindValue(":newValue", value);
    query.bindValue(":Username", usrnam);
    query.bindValue(":Password", psswrd);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record update successful";
        }else{
            qDebug() << "DATABASE:: Record update unsuccessful - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::UserExits(QString usrNam, QString psswrd)
{
    bool exists = false;
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE Username = :usrNam AND Password = :psswrd");
    query.bindValue(":usrNam", usrNam);
    query.bindValue(":psswrd", psswrd);
    if (query.exec()){
        if(query.next()){
            exists = true;
        }
    }
    return exists;
}

QList<QVariant> DBManager::getUserData(QString usrNam, QString psswrd) const
{
    QSqlQuery query;
    QList<QVariant> list;

    query.prepare("SELECT User_Id, First_Name, Last_Name, Email, Username, Password"
                  " FROM Users WHERE Username = :usrNam AND Password = :psswrd");
    query.bindValue(":usrNam", usrNam);
    query.bindValue(":psswrd", psswrd);

    if (!query.exec()){
        qDebug() << "DATABASE:: Failed to retrieve data from Users table - " << query.lastError();
    } else {
        if (query.first()) {
            list.append(query.value("User_Id"));
            list.append(query.value("First_Name"));
            list.append(query.value("Last_Name"));
            list.append(query.value("Email"));
            list.append(query.value("Username"));
            list.append(query.value("Password"));
        } else {
            qDebug () << "DATABASE:: Data not found";
        }
    }
    return list;
}

//Accounts Table
bool DBManager::insertAccount(int usrId, double value)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;
    query.prepare("INSERT INTO Accounts(User_Id, Balance)"
                  "VALUES (:User_Id, :Balance)");
    query.bindValue(":User_Id", usrId);
    query.bindValue(":Balance", value);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record insert successful";
        }else{
            qDebug() << "DATABASE:: Record insert unsuccessful - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::deleteAccount(int AccNum)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;
    query.prepare("DELETE FROM Accounts WHERE Account_Number = :Account_Number");
    query.bindValue(":Account_Number", AccNum);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record deleted successfully";
        }else{
            qDebug() << "DATABASE:: Record deletion failed - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::updateAccount(int AccNum, double value)
{
    DB_LAST_SAVED
    QSqlQuery query;
    bool status = false;

    query.prepare("UPDATE Accounts SET Balance = :newValue WHERE Account_Number = :Account_Number");
    query.bindValue(":newValue", value);
    query.bindValue(":Account_Number", AccNum);

    if(AppDatabase.isOpen()){
        if(query.exec()){
            status = true;
            qDebug() << "DATABASE:: Record update successful";
        }else{
            qDebug() << "DATABASE:: Record update unsuccessful - " << query.lastError();
        }
    }else{
        qDebug() << "DATABASE:: not open ";
    }
    return status;
}

bool DBManager::AccountExits(int AccNum)
{
    bool exists = false;
    QSqlQuery query;
    query.prepare("SELECT * FROM Accounts WHERE Account_Number = :accNum");
    query.bindValue(":accNum", AccNum);

    if (query.exec()){
        if(query.next()){
            exists = true;
        }
    }
    return exists;
}

QList<QVariant> DBManager::getAccountData(int AccNum) const
{
    QSqlQuery query;
    QList<QVariant> list;

    query.prepare("SELECT Account_Number, Balance"
                  " FROM Accounts WHERE Account_Number = :accNum");
    query.bindValue(":accNum", AccNum);

    if (!query.exec()){
        qDebug() << "DATABASE:: Failed to retrieve data from Accounts table - " << query.lastError();
    } else {
        if (query.first()) {
            //list.append(query.value("User_Id"));
            list.append(query.value("Account_Number"));
            list.append(query.value("Balance"));
        } else {
            qDebug () << "DATABASE:: Data not found";
        }
    }
    return list;
}


