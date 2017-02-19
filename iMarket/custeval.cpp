#include "custeval.h"
#include "ui_custeval.h"

custeval::custeval(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::custeval)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    if(!ret)
    {
        qDebug()<<"connect fail";
    }
}

custeval::~custeval()
{
    delete ui;
}

void custeval::on_pushButton_clicked()
{
    bool f=ui->checkBox->isChecked();
    QString sql;
    if(f)
    {
        sql=("insert into evaluation(item,isgood,eval)values(\""+ui->lineEdit->text()+"\",1,\""+ui->textEdit->toPlainText()+"\")");
    }
    else
    {
        sql=("insert into evaluation(item,isgood,eval)values(\""+ui->lineEdit->text()+"\",0,\""+ui->textEdit->toPlainText()+"\")");
    }
    qDebug()<<sql;
    QSqlQuery sqy;
    sqy.prepare(sql);
    if(sqy.exec())
    {
        QMessageBox::information(this,"ok","ok");
    }
    else
    {
        QMessageBox::information(this,"fail","fail");
    }

}
