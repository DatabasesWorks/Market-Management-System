#include "stockfrom.h"
#include "ui_stockfrom.h"

stockfrom::stockfrom(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::stockfrom)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    if(!ret)
    {
        qDebug()<<d->db.lastError();
    }
}

stockfrom::~stockfrom()
{
    delete ui;
}

void stockfrom::on_pushButton_clicked()
{
    QString sql("update item set amount = amount+"+ui->lineEdit_2->text()+" where name = "+ui->lineEdit->text());
    qDebug()<<sql;
    QSqlQuery sqy;
    sqy.prepare(sql);
    sqy.exec();
    sql="insert into stock(item,amount,stockdate)values(\""+ui->lineEdit->text()+"\" ,"+ui->lineEdit_2->text()+" ,now()"+")";
    qDebug()<<sql;
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
