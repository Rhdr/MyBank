#include <QApplication>
#include "Core/UserManager.h"
#include "Ui/mainappwindow.h"
#include "Ui/loginscreen.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UserManager usrmanager;
    bool loginStatus = false;
    User currentUser;

    LoginScreen lgnScrn;
    lgnScrn.show();

    auto input = lgnScrn.getInput();
    QString username = input.at(0);
    QString password = input.at(1);

    if(usrmanager.validateUser(username, password)){
        loginStatus = true;
        currentUser = usrmanager.loadUserData(username, password);;
    }
    return a.exec();
}
