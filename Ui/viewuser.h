#ifndef VIEWUSER_H
#define VIEWUSER_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QGridLayout>
#include <QPushButton>

class ViewUser : public QWidget
{
    Q_OBJECT
public:
    explicit ViewUser(QWidget *parent = 0);
    QLabel *lblUserId;
    QSpinBox *spnUserId;
    QLabel *lblFirstName;
    QLineEdit *txtFirstName;
    QLabel *lblLastName;
    QLineEdit *txtLastName;
    QLabel *lblUsername;
    QLineEdit *txtUsername;
    QLabel *lblPassword;
    QLineEdit *txtPassword;
    QLabel *lblEmail;
    QLineEdit *txtEmail;
    QPushButton *btnSave;


signals:

public slots:



};

#endif // VIEWUSER_H
