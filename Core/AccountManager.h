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
#include "Account.h"
#include "dbmanager.h"

namespace Manager {
    class AccountManager
    {
    public:
        /*
         * Initiallises the dbmanager instance
        */
        AccountManager();

        /*
         * Creates an object of type Account
         * param : an initial amount
         * returns an object of type Account if the process was successful
        */
        Account createAccount(double bal);

        /*
         * Adds an account to the database
         * param : The user's id
         *       : An object of type Account by reference which the user created
         * returns an object of type Account if the process was successful
        */
        bool addAcount(int usrId, Account& acc);

        /*
         * Updates an account balance since that's the only field users are allowed to change
         * param : The account number of the account to be updated
         *       : The new balance
         * returns true if the process was successful otherwise it returns false
        */
        bool updateAccount(int accNum, double newValue);

        /*
         * Deletes an account
         * param : The account number of the account to be updated
         * returns true if the process was successful otherwise it returns false
        */
        bool deleteAccount(int accNum);

        /*
         * Checks if an account exists or not
         * param : The account number of the account to be updated
         * returns true if the process was successful otherwise it returns false
        */
        bool isValid(int accNum);

        /*
         * Loads Account info
         * param : The account number of the account to be updated
         * returns an object of type Account if the process was successful
        */
        Account loadAccountInfo(int accNum);
    private:
        DBManager* dbmanager;
    };
}


