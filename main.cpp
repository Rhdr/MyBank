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
    int currentUser_ID = 0;
    Account acc1;

    //Input from the view
    QString username = "zielinkin1";
    QString password = "123456";
    currentUser.setUserName(username);
    currentUser.setPassWord(password);

    if(usrmanager.validateUser(currentUser)){
        //loginStatus = true;
        currentUser = usrmanager.loadUserData(currentUser);
        currentUser_ID = currentUser.getUserId();
        w.show(); //Application crashes if window not shown
    }

    //run app until login status is false.
    return a.exec();
}

