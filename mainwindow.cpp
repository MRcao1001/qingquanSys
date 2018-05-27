#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "regwindow.h"
#include "ui_regwindow.h"
#include <QMessageBox>
#include <QMovie>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_reg_clicked()
{
    newrw = new regwindow(this);
    newrw->move(750,150);
    newrw->show();
}

void MainWindow::on_btn_login_clicked()
{
    newlw = new loginwindow(this);
    newlw->move(750,150);
    newlw->show();
}

void MainWindow::on_btn_exit_clicked()
{
    QMessageBox::critical(this,"你居然打我的脸","君子动口不动手不懂么！居然打我的脸，再见");
    this->close();
}

void MainWindow::on_btn_admin_clicked()
{
    QMessageBox::critical(this,"哎呦不错哦，居然发现了管理员入口","然而并没有什么卵用，我们禁用了管理员功能");

}
