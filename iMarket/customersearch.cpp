#include "customersearch.h"
#include "ui_customersearch.h"

customersearch::customersearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customersearch)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    this->curr=0;
    this->carry=4;
    this->groupby="all";
    ui->currnum->setText(QString::number(this->curr+1));
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    if(ret)
    {
        this->print("all");
    }
}
void customersearch::print(QString a)
{
    QSqlQueryModel model;
    if(a=="all")
    {
        model.setQuery("SELECT name,price,location,amount FROM item limit "+QString::number(this->carry*this->curr)+",4");
    }
    else
    {
        qDebug()<<"SELECT name,price,location,amount FROM item where category = "+a+" limit "+QString::number(this->carry*this->curr)+",4";
        model.setQuery("SELECT name,price,location,amount FROM item where category = \""+a+"\" limit "+QString::number(this->carry*this->curr)+",4");
    }
    ui->l11->setText(model.record(0).value(0).toString());
    ui->l12->setText(model.record(0).value(1).toString());
    ui->l13->setText(model.record(0).value(2).toString());
    ui->l14->setText(model.record(0).value(3).toString());

    ui->l21->setText(model.record(1).value(0).toString());
    ui->l22->setText(model.record(1).value(1).toString());
    ui->l23->setText(model.record(1).value(2).toString());
    ui->l24->setText(model.record(1).value(3).toString());

    ui->l31->setText(model.record(2).value(0).toString());
    ui->l32->setText(model.record(2).value(1).toString());
    ui->l33->setText(model.record(2).value(2).toString());
    ui->l34->setText(model.record(2).value(3).toString());

    ui->l41->setText(model.record(3).value(0).toString());
    ui->l42->setText(model.record(3).value(1).toString());
    ui->l43->setText(model.record(3).value(2).toString());
    ui->l44->setText(model.record(3).value(3).toString());
}

customersearch::~customersearch()
{
    delete ui;
}

void customersearch::on_pushButton_6_clicked()
{
    this->curr--;
    ui->currnum->setText(QString::number(this->curr+1));
    this->print(this->groupby);
}

void customersearch::on_pushButton_7_clicked()
{
    this->curr++;
    ui->currnum->setText(QString::number(this->curr+1));
    this->print(this->groupby);
}

void customersearch::on_pushButton_8_clicked()
{
    qDebug()<<ui->lineEdit->text().toInt();
    this->curr=ui->lineEdit->text().toInt()-1;
    ui->currnum->setText(QString::number(this->curr));
    this->print(this->groupby);
}

void customersearch::on_pushButton_2_clicked()
{
    ui->currnum->setText(QString::number(this->curr+1));
    this->groupby="fruit";
    this->curr=0;
    this->print(this->groupby);
}

void customersearch::on_pushButton_3_clicked()
{
    ui->currnum->setText(QString::number(this->curr+1));
    this->groupby="food";
    this->curr=0;
    this->print(this->groupby);
}

void customersearch::on_pushButton_4_clicked()
{
    ui->currnum->setText(QString::number(this->curr+1));
    this->groupby="clothes";
    this->curr=0;
    this->print(this->groupby);
}

void customersearch::on_pushButton_5_clicked()
{
    ui->currnum->setText(QString::number(this->curr+1));
    this->groupby="sports";
    this->curr=0;
    this->print(this->groupby);
}

void customersearch::on_pushButton_clicked()
{
    ui->currnum->setText(QString::number(this->curr+1));
    this->groupby="all";
    this->curr=0;
    this->print(this->groupby);
}
