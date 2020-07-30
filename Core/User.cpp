#include "User.h"

User::User(){}

User::User(QString fnam, QString lnam, QString eml, QString usrnam, QString psswrd)
{
	firstname = fnam;
	lastname = lnam;
	username = usrnam;
	password = psswrd;
	email = eml;
}

void User::setFirstName(QString fnam)
{
	firstname = fnam;
}

void User::setLastName(QString lnam)
{
	lastname = lnam;
}

void User::setUserName(QString usrnam)
{
	username = usrnam;
}

void User::setPassWord(QString psswrd)
{
	password = psswrd;
}

void User::setEmail(QString eml)
{
    email = eml;
}

void User::setUserId(int usrId)
{
    user_id = usrId;
}

int User::getUserId() const
{
    return  user_id;
}

QString User::getFirstName() const
{
	return firstname;
}

QString User::getLastName() const
{
	return lastname;
}

QString User::getUserName() const
{
	return username;
}

QString User::getPassWord() const
{
	return password;
}

QString User::getEmail() const
{
    return email;
}

