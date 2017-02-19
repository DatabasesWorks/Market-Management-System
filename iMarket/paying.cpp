#include "paying.h"
#include "ui_paying.h"

paying::paying(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::paying)
{
    ui->setupUi(this);
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    setFixedSize(1050,650);
    if(!ret)
    {
        QMessageBox::information(this,"fail","open db gg");
    }
    bill.clear();
}

paying::~paying()
{
    delete ui;
}

void paying::on_pushButton_clicked()
{
    QSqlQueryModel model;
    model.setQuery("SELECT price FROM item where name = \""+ui->lineEdit_3->text()+"\"");
    float price=model.record(0).value(0).toFloat();
    //qDebug()<<price;
    qDebug()<<"SELECT price FROM item where name = "+ui->lineEdit_3->text();
    bill.insert(ui->lineEdit_3->text(),std::make_pair(ui->lineEdit->text().toInt(),ui->lineEdit->text().toInt()*price) );
    ui->listWidget->addItem(ui->lineEdit_3->text()+"               "+ui->lineEdit->text()+"               "+QString::number(price*ui->lineEdit->text().toInt()));
}

void paying::on_pushButton_3_clicked()
{
    qDebug()<<ui->listWidget->currentItem()->text().split(" ")[0];
    bill.remove(ui->listWidget->currentItem()->text().split(" ")[0]);
    int curr=ui->listWidget->currentIndex().row();
    ui->listWidget->takeItem(curr);
    foreach(QString ky,bill.keys())
    {
        qDebug()<<ky<<" "<<bill[ky].first<<" "<<bill[ky].second;
    }
}

void paying::on_pushButton_2_clicked()
{
    dbhandler* d=dbhandler::getInstance();
    QSqlQuery sqy;
    bool ret=true;
    //rapidjson::StringBuffer s;
    //rapidjson::Writer<rapidjson::StringBuffer> writer(s);
    //writer.StartObject();
    foreach(QString ky,bill.keys())
    {
        QString sql("update item set amount = amount-"+QString::number(bill[ky].first)+" where name = \""+ky+"\"");
        qDebug()<<sql;
        sqy.prepare(sql);
        ret=ret&&sqy.exec();
        //QByteArray ba = ky.toLatin1();
        //const char *c = ba.data();
        //writer.Key(c);
        //writer.Double(bill[ky].second);
    }
    //qDebug()<<s.GetString();

    QString res;
    float all=0;
    foreach(QString ky,bill.keys())
    {
        all+=bill[ky].second;
        res=res+ky+" "+QString::number(bill[ky].second)+"\n";
    }
    //writer.Key("all: ");
    //writer.Double(all);
    //writer.EndObject();
    //qDebug()<<QString(s.GetString());
    res=res+"total : "+QString::number(all);
    QString sql("insert into dealing(bill,total,stockdate) values(\""+res+"\","+QString::number(all)+",now());");
    sqy.prepare(sql);
    qDebug()<<sql;
    ret=ret&&sqy.exec();
    if(ret)
    {
        d->db.commit();
        QMessageBox::information(this,"ok",res);
    }





}
