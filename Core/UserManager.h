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
#include "User.h"
#include "dbmanager.h"

namespace Manager {
    class UserManager
    {
    public:
        UserManager();
        /*	Creates a user
            param : fnam the user's first name
                  : lnam the user's last name
                  : eml the user's email address
                  : usrnam the user's username
                  : psswrd the user's password
            returns a new User object
        */
        User createUser(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd);

        //Adds a new user
        //param : a User class object by reference,
        //returns true if the user was added otherwise returns false
        bool addUser(User& usr);

        /*Updates a user
          param : a User class object by reference,
                : an integer representing the field to be updated
                : "First_Name" 0,
                  "Last_Name"  1,
                  "Email"      2,
                  "Username"   3,
                  "Password"   4.
                : the new value
          returns true if the procedure was successful and false if it failed*/
        bool updateUser(User& usr, int flag, QVariant value);

        //Deletes a user
        //returns true if the user was deleted otherwise returns false
        bool deleteUser(User& usr);

        //Checks if the user is a valid User
        //param : a User class object by reference,
        //returns true if the user is valid and false if the user is not in application's database
        bool validateUser(User& usr);

        //Loads User data provided the username and password provided are valid
        //param : a User class object by reference,
        //returns a User object
        User loadUserData(User& usr);

    private:
        DBManager* dbmanager;
    };
}

