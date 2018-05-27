#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "regwindow.h"
#include "loginwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_reg_clicked();

    void on_btn_login_clicked();

    void on_btn_exit_clicked();

    void on_btn_admin_clicked();

private:
    Ui::MainWindow *ui;
    regwindow *newrw;
    loginwindow *newlw;
};

#endif // MAINWINDOW_H
