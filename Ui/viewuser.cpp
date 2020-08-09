#include "viewuser.h"

ViewUser::ViewUser(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowTitle("User");
    //ensure the widget gets deleted propertly when the view close (and not just hidden)
    this->setAttribute(Qt::WA_DeleteOnClose);

    //create objects    //parent will be the layout
    QLabel *lblUserId = new QLabel("User_Id");
    QSpinBox *spnUserId = new QSpinBox();

    QLabel *lblFirstName = new QLabel("First Name");
    QLineEdit *txtFirstName = new QLineEdit();

    QLabel *lblLastName = new QLabel("Last Name");
    QLineEdit *txtLastName = new QLineEdit();

    QLabel *lblUsername = new QLabel("Username");
    QLineEdit *txtUsername = new QLineEdit();

    QLabel *lblPassword = new QLabel("Password");
    QLineEdit *txtPassword = new QLineEdit();

    QLabel *lblEmail = new QLabel("Email");
    QLineEdit *txtEmail = new QLineEdit();

    QPushButton *btnSave = new QPushButton("Save");


    //setup Layout      //parent will be the ViewUser form
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(lblUserId, 0, 0);
    layout->addWidget(spnUserId, 0, 1);

    layout->addWidget(lblFirstName, 1, 0);
    layout->addWidget(txtFirstName, 1, 1);

    layout->addWidget(lblLastName, 2, 0);
    layout->addWidget(txtLastName, 2, 1);

    layout->addWidget(lblUsername, 3, 0);
    layout->addWidget(txtUsername, 3, 1);

    layout->addWidget(lblPassword, 4, 0);
    layout->addWidget(txtPassword, 4, 1);

    layout->addWidget(lblEmail, 5, 0);
    layout->addWidget(txtEmail, 5, 1);

    layout->addWidget(btnSave, 6, 0, 1, 2);

    //set ViewUser's layout
    this->setLayout(layout);

}
