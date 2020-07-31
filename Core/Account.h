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

class Account
{
public:
    /*
     * Initialises the balance to zero
    */
    Account();

    /*
     * Initialises the balance to bal
     * param : The new balance
    */
    Account(double bal);

    /*
     * Changes the balance to bal
     * param : The new balance
    */
    void setBalance(double bal);

    /*
     * Changes the accountNumber to accNum
     * param : The new account number
    */
    void setAccountNumber(int accNum);

    double getBalance() const; // returns the balance
    int getAccountNumber() const; // returns the account number
private:
    double balance; // Account's balance
    int accountNumber; // Account's account number
};

