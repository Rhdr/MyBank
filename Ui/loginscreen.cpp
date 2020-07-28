#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QLineEdit>


LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

QList<QString> LoginScreen::getInput() const
{
    QList<QString> inputList;
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();
    inputList.append(username);
    inputList.append(password);
    return inputList;
}

void LoginScreen::on_login_pushButton_clicked()
{




}
