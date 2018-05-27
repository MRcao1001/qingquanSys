#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include "userwindow.h"
namespace Ui {
class loginwindow;
}

class loginwindow : public QDialog
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = 0);
    ~loginwindow();
    int redFormFile();
    void dologin(QString phone,QString pwd);
private slots:
    void on_login_clicked();

private:
    Ui::loginwindow *ui;
    QList<QString> stu_line;
    userwindow *newuw;
};

#endif // LOGINWINDOW_H
