#include "contuser.h"

ContUser::ContUser(Manager::UserManager *modelObj, ViewUser *viewObj, QObject *parent) :
    model(modelObj), view(viewObj), QObject(parent)
{
    QObject::connect(view->btnSave, SIGNAL(clicked()),
                     this, SLOT(btnSave_clicked()));
    view->show();
}

ContUser::~ContUser()
{
    delete view;
    delete model;
}

void ContUser::btnSave_clicked()
{
    //if (isNewUser):
    //{
        User newUser = model->createUser(view->txtFirstName->text(),
                                         view->txtLastName->text(),
                                         view->txtEmail->text(),
                                         view->txtUsername->text(),
                                         view->txtPassword->text());
        model->addUser(newUser);
    //} else {   //editExisting user
    //}
}
