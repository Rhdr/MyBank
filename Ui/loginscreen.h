#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
#include "Core/UserManager.h"

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();
    QList<QString> getInput() const;

private slots:

    void on_login_pushButton_clicked();

private:
    UserManager usrManager;
    Ui::LoginScreen *ui;
};

#endif // LOGINSCREEN_H
