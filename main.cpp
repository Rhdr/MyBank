#include <QApplication>
#include "Core/UserManager.h"
#include "Core/AccountManager.h"
#include "Ui/mainappwindow.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserManager usrmanager;
    AccountManager accmanager;
    MainAppWindow w;
    w.show();

    bool loginStatus = false;
    User currentUser;

    QString username = "zielinkin1";
    QString password = "123456";

    if(usrmanager.validateUser(username, password)){
        loginStatus = true;
        currentUser = usrmanager.loadUserData(username, password);
    }
    //run app until login status is false.
    return a.exec();
}

