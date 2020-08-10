#ifndef CONTUSER_H
#define CONTUSER_H

#include <QObject>
#include "Core/UserManager.h"
#include "Ui/viewuser.h"

class ContUser : public QObject
{
    Q_OBJECT
public:
    explicit ContUser(Manager::UserManager *modelObj, ViewUser *viewObj, QObject *parent = 0);
    ~ContUser();

private:
    Manager::UserManager *model;
    ViewUser *view;

signals:


private slots:
    void btnSave_clicked();

};

#endif // CONTUSER_H
