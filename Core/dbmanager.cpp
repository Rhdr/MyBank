#include "dbmanager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

DBManager::DBManager()
{
    AppDatabase = QSqlDatabase::addDatabase("QSQLITE");
    AppDatabase.setDatabaseName("MyBankDB.db");

    if (!AppDatabase.open()){
        qDebug() << "DATABASE:: Failed to connect to database - " << AppDatabase.lastError();
    }else{
        qDebug() << "DATABASE:: Connection successful";
    }
}

DBManager::~DBManager()
{
    if (AppDatabase.isOpen()){
        AppDatabase.close();
        QSqlDatabase::removeDatabase("MyBankDB.db");
        qDebug() << "DATABASE:: Database closed";
    }
}

bool DBManager::isOpen() const
{
    return AppDatabase.isOpen();
}

bool DBManager::insertUser(User& usr)
{
    QSqlQuery query;
    bool status = false;
    query.prepare("INSERT INTO Users(First_Name, Last_Name, Email, Username, Password)"
                  "VALUES (:First_Name, :Last_Name, :Email, :Username, :Password)");
    query.bindValue(":First_Name", usr.getFirstName());
    query.bindValue(":Last_Name", usr.getLastName());
    query.bindValue(":Email", usr.getEmail());
    query.bindValue(":Username", usr.getUserName());
    query.bindValue(":Password", usr.getPassWord());

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

bool DBManager::deleteUser(User& usr)
{
    QSqlQuery query;
    bool status = false;
    query.prepare("DELETE FROM Users WHERE Username = :Username");
    query.bindValue(":Username", usr.getUserName());
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

bool DBManager::updateUser(User& usr, int flag, QVariant& value)
{
    QSqlQuery query;
    bool status = false;
    QString temp_value = "";
    QList<QString> fieldlist = {"First_Name", "Last_Name", "Email", "Username", "Password"};
    QString field = fieldlist.at(flag);

    if(field == "First_Name") {
        usr.setFirstName(value.toString());
        temp_value = usr.getFirstName();
    }else if (field == "Last_Name") {
        usr.setLastName(value.toString());
        temp_value = usr.getLastName();
    }else if (field == "Email") {
        usr.setEmail(value.toString());
        temp_value = usr.getEmail();
    }else if (field == "Username") {
        usr.setUserName(value.toString());
        temp_value = usr.getUserName();
    }else if (field == "Password") {
        usr.setPassWord(value.toString());
        temp_value = usr.getPassWord();
    }else{
        qDebug() << "invalid option";
    }

    query.prepare("UPDATE Users SET " + field + " = :newValue WHERE Username = :Username");
    query.bindValue(":newValue",temp_value);
    query.bindValue(":Username",usr.getUserName());

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

bool DBManager::UserExits(QString usrNam, QString psswrd){

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

    query.prepare("SELECT First_Name, Last_Name, Email, Username, Password"
                  " FROM Users WHERE Username = :usrNam AND Password = :psswrd");
    query.bindValue(":usrNam", usrNam);
    query.bindValue(":psswrd", psswrd);

    if (!query.exec()){
        qDebug() << "DATABASE:: Failed to retrieve data from Users table - " << query.lastError();
    } else {
        if (query.first()) {
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
