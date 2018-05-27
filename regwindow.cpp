#include "regwindow.h"
#include "ui_regwindow.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QTime>


regwindow::regwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regwindow)
{
    ui->setupUi(this);
    //返回按钮功能
    connect(this->ui->btn_cancle,SIGNAL(clicked(bool)),this,SLOT(close()));
}

regwindow::~regwindow()
{
    delete ui;
}

//确定按钮功能
void regwindow::on_btn_enter_clicked()
{
    QDateTime current_date_time =QDateTime::currentDateTime();
    QString current_date =current_date_time.toString("yyyyMMddhhmmss");
    QString name = this->ui->line_name->text();
    QString phone = this->ui->line_phone->text();
    QString pwd = this->ui->line_pwd->text();
    QString pwd2 = this->ui->line_pwd_2->text();
    QString bick = "暂无疗程";
    QString blance = "0";
    QString content = "姓名："+name+'\n' +"电话："+ phone+'\n' +"密码："+ pwd;
    QString cnt = name + " " + phone + " " + pwd + " " +bick+ " " +blance+" "+current_date+"\n";
    //开始检查输入
    if(pwd != pwd2)
    {
        QMessageBox msgBox;
        msgBox.setText("您两次输入密码不一样，请重试                ");
        msgBox.setInformativeText("密码 ："+pwd+"\n"+"密码2 ："+pwd2+"\n");
        msgBox.addButton(" 好 ",QMessageBox::AcceptRole);
        msgBox.exec();
    }
    else if(name.size()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("请输入姓名                   ");
        msgBox.addButton(" 好 ",QMessageBox::AcceptRole);
        msgBox.exec();
    }
    else if(phone.size()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("请输入手机号，这很重要              ");
        msgBox.addButton(" 好 ",QMessageBox::AcceptRole);
        msgBox.exec();
    }
    else if(pwd.size()==0)
    {
        QMessageBox msgBox;
        msgBox.setText("请输入密码                  ");
        msgBox.addButton(" 好 ",QMessageBox::AcceptRole);
        msgBox.exec();
    }
    else if(ui->checkBox->isChecked()!=true)
    {
       QMessageBox::critical(this,"请先同意许可条约","如果您不勾选许可条约我们无法为您注册");

   }
    //检查输入结束

    else
    {
        int ret = QMessageBox::question(this,"确认信息无误么？                ",content,"确认","取消");
        if(ret == 0)
        {
            //确认信息之后将信息写入文件并且跳转到登录界面
            writeToFile(cnt);
            this->close();
            newlw = new loginwindow(this);
            newlw->move(750,150);
            newlw->show();
        }
    }


}
void regwindow::writeToFile(QString cnt)
{
    QFile file("user.dat");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        QMessageBox::critical(this,"暂时无法将信息写入资源，请重试！","确定");
        return;
    }

    QTextStream out(&file);
    out << cnt;
    file.close();
}
