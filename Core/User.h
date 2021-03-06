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
#include <QString>

class User
{
public:
    User();
    /* initializes the private members of class User
     * param : fnam the user's first name
     *       : lnam the user's last name
     *       : usrnam the user's username
     *       : psswrd the user's password
     *       : eml the user's email address
    */
    User(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd);

    /*
     * Changes firstname to fnam
     * param : The new user's first name
    */
    void setFirstName(QString fnam);

    /*
     * Changes lastname to lnam
     * param : The new user's last name
    */
    void setLastName(QString lnam);

    /*
     * Changes username to usrnam
     * param : The new user's username
    */
    void setUserName(QString usrnam);

    /*
     * Changes password to psswrd
     * param : The new user's password
    */
    void setPassWord(QString psswrd);

    /*
     * Changes email to eml
     * param : The new user's email
    */
    void setEmail(QString eml);

    /* Changes the user_id to usrId
     * param : The new user id
    */
    void setUserId(int usrId);

    int getUserId() const; // returns the user id of the user
    QString getFirstName() const; // returns the first name of the user
    QString getLastName() const; // returns the last name of the user
    QString getUserName() const; // returns the user name of the user
    QString getPassWord() const; // returns the password of the user
    QString getEmail() const; // returns the email of the user

private:
    int user_id;
    QString firstname; //user's first name
    QString lastname; //user's last name
    QString username; //user's username
    QString password; //user's password
    QString email; //user's email address
};

