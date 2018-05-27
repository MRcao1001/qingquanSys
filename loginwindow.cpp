#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>

loginwindow::loginwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
    if (redFormFile() == -1)//在构造函数中调用读取文件操作
    {
        QMessageBox::critical(this,"发生错误","数据出错，请重启程序");
        this->close();
    }

}

loginwindow::~loginwindow()
{
    delete ui;
}

void loginwindow::on_login_clicked()
{
    QString phone = this->ui->phone->text();
    QString pwd = this->ui->pwd->text();
    dologin(phone,pwd);
}

int loginwindow::redFormFile()
{
    QFile file("user.dat");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }
    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        stu_line.append(line);
    }
    file.close();
//在后台打印所有学生信息
    int i = 0;
    for(i = 0; i< stu_line.length(); i++){
        qDebug()<<stu_line.at(i);
    }
    return 0;
}

QString name;
QString phone_2;
QString password;
QString bick;
QString balance;
QString time_0;
void loginwindow::dologin(QString phone, QString pwd)
{
    int i = 0;

    for(i =0;i <stu_line.length();i++)
    {
        QString line = stu_line.at(i);
        line = line.trimmed();//去掉末尾空白字符串
        QStringList subs = line.split(" ");
        if(phone == subs.at(1) && pwd == subs.at(2))
        {
            name = subs.at(0);
            phone_2 = phone;
            password = pwd;
            bick = subs.at(3);
            balance = subs.at(4);
            time_0 = subs.at(5);
            qDebug()<<"登录界面" + time_0;
            ui->tips->setStyleSheet("color:green;");
            ui->tips->setText("登录成功");
            newuw = new userwindow(this);
            newuw->move(750,150);
            newuw->show();
            //this->close();
            break;
        }
        else
        {
            ui->tips->setStyleSheet("color: rgb(136, 138, 133);");
            ui->tips->setText("密码错误");
        }
    }
}
































