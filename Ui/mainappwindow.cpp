#include "mainappwindow.h"
#include "ui_mainappwindow.h"

MainAppWindow::MainAppWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainAppWindow)
{
    ui->setupUi(this);
}

MainAppWindow::~MainAppWindow()
{
    delete ui;
}
