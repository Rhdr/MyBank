/*********************************************************************
 *MyBank
 *Copyright (C) 2020 By Zibusiso N Mangoye
 *Contact : znmangoye@gmail.com
 *
 *This program is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *This program is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *
 *You should have received a copy of the GNU General Public License
 *along with this program.  If not, see <http://www.gnu.org/licenses/>.
************************************************************************/

#pragma once
#include <QSqlDatabase>
#include <QList>
#include <QVariant>
#include "User.h"
#include "Account.h"

class DBManager
{
public:
    static DBManager* getInstance();

    //Closes the database connection
    ~DBManager();

    //Checks if the database is open or not
    //returns true if the database is open or false if not open
    bool isOpen() const;

    //Inserts a new user to the database(table Users)
    //param : a User class object by reference,
    //returns true if the procedure was successful and false if the insertion failed
    bool insertUser(User& usr);

    //Deletes a new user in the database(table Users)
    //param : a User class object by reference,
    //returns true if the procedure was successful and false if the deletion failed
    bool deleteUser(User& usr);

    /*Updates a user in the database(table Users)
      param : a User class object by reference,
            : an integer representing the field to be updated
            : "First_Name" 0,
              "Last_Name"  1,
              "Email"      2,
              "Username"   3,
              "Password"   4.
            : the new value
      returns true if the procedure was successful and false if it failed*/
    bool updateUser(User& usr, int flag, QVariant& value);

    //Checks if the user exists
    //param : the username
    //      : the password
    //returns true if the user exists and false if the user does not exists
    bool UserExits(QString usrNam, QString psswrd);

    //Retrives User data from database
    //param : the username
    //      : the password
    //returns the data as qvariants in a qlist or an empty list if the user was not found.
    //this function should be called after UserExits()
    QList<QVariant> getUserData(QString usrNam, QString psswrd) const;

    //Inserts a new account to the database(table Accounts)
    //param : a Account class object by reference,
    //returns true if the procedure was successful and false if the insertion failed
    bool insertAccount(int usrId, Account& acc);

    //Deletes a new account in the database(table Accounts)
    //param : a Account class object by reference,
    //returns true if the procedure was successful and false if the deletion failed
    bool deleteAccount(Account& acc);

    /*Updates a account in the database(table Accounts)
      param : a Account class object by reference,
            : the new value
      returns true if the procedure was successful and false if it failed*/
    bool updateAccount(Account& acc, double value);

    //Checks if the account exists
    //param : a Account class object by reference, this is the account in question
    //returns true if the user exists and false if the user does not exists
    bool AccountExits(Account& acc);

    //Retrives Account data from database
    //param : a Account class object by reference, this is the account in question
    //returns the data as qvariants in a qlist or an empty list if the user was not found.
    //this function should be called after AccountExits()
    QList<QVariant> getAccountData(Account& acc) const;

private:
    QSqlDatabase AppDatabase;

    //Opens the database connection
    DBManager();
    static DBManager* dbManagerInstance;
};
