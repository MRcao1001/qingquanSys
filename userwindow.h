#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
namespace Ui {
class userwindow;
}

class userwindow : public QDialog
{
    Q_OBJECT

public:
    explicit userwindow(QWidget *parent = 0);
    ~userwindow();
    long long gettime();
    int readFromFile();
    int writeFromFile();
    int getbick(QString name);
    int getbick_2(QString name,QString bicktype);
    int returnbick(QString name,QString bicktype);
    int getmoney(QString name,QString balance_2);
    int upinfo();
private slots:
    void on_but_sup_clicked();

    void on_but_chi_clicked();

    void on_but_love_clicked();

    void on_but_nom_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::userwindow *ui;
    QList<QString> stu_line;

};

#endif // USERWINDOW_H









