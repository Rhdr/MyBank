#ifndef MAINAPPWINDOW_H
#define MAINAPPWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainAppWindow;
}

class MainAppWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainAppWindow(QWidget *parent = nullptr);
    ~MainAppWindow();

private:
    Ui::MainAppWindow *ui;
};

#endif // MAINAPPWINDOW_H
