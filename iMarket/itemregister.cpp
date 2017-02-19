#include "itemregister.h"
#include "ui_itemregister.h"

itemregister::itemregister(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemregister)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
}

itemregister::~itemregister()
{
    delete ui;
}

void itemregister::on_pushButton_clicked()
{
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    if(ret)
    {

        //d.db.exec("use imarket;");
        QString sql("insert into imarket.item (name,price,stockprice,category,location,amount) values(\""+ui->lineEdit->text()+"\","+ui->lineEdit_2->text()+","+ui->lineEdit_3->text()+",\""+ui->lineEdit_6->text()+"\",\""+ui->lineEdit_4->text()+"\","+ui->lineEdit_5->text()+")");
        //qDebug()<<sql;
        QSqlQuery sqy;
        sqy.prepare(sql);
        /*
        sqy.addBindValue(ui->lineEdit->text());
        sqy.addBindValue(ui->lineEdit_2->text().toInt());
        sqy.addBindValue(ui->lineEdit_3->text().toInt());
        sqy.addBindValue(2);
        sqy.addBindValue(ui->lineEdit_4->text());
        sqy.addBindValue(ui->lineEdit_5->text().toInt());
        */
        if(sqy.exec())
        {
            QMessageBox::information(this,"ok","ok");
        }
        else
        {
            QMessageBox::information(this,"fail","fail");
        }

    }
    else
    {
        qDebug() <<"db open fail";
    }
}
