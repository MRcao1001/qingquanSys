#ifndef REGWINDOW_H
#define REGWINDOW_H

#include <QDialog>
#include "loginwindow.h"
namespace Ui {
class regwindow;
}

class regwindow : public QDialog
{
    Q_OBJECT

public:
    explicit regwindow(QWidget *parent = 0);
    ~regwindow();
    void writeToFile(QString cnt);
private slots:
    void on_btn_enter_clicked();

private:
    Ui::regwindow *ui;
    loginwindow *newlw;

};

#endif // REGWINDOW_H
