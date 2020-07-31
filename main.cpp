#include <QApplication>
#include "Core/UserManager.h"
#include "Core/AccountManager.h"
#include "Ui/mainappwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Manager::UserManager usrmanager;
    Manager::AccountManager accmanager;
    MainAppWindow w;


    //bool loginStatus = false;
    User currentUser;
    //Account acc1 = accmanager.createAccount(0.0);

    QString username = "zielinkin1";
    QString password = "123456";

    if(usrmanager.validateUser(username, password)){
        //loginStatus = true;
        currentUser = usrmanager.loadUserData(username, password);
        w.show();
    }
//    populating the accounts table in the database
//    for (int i=0; i < 5; i++) {
//        accmanager.addAcount(currentUser.getUserId(), acc1);
//    }

    //run app until login status is false.

    return a.exec();
}

