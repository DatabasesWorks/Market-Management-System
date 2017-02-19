#include "search.h"
#include "ui_search.h"
void search::print()
{
    QSqlQueryModel model;
    model.setQuery("SELECT name,price,location,category,amount FROM item limit "+QString::number(this->carry*this->curr)+",5");
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

    ui->l51->setText(model.record(4).value(0).toString());
    ui->l52->setText(model.record(4).value(1).toString());
    ui->l53->setText(model.record(4).value(2).toString());
    ui->l54->setText(model.record(4).value(3).toString());

    ui->amount1->setText(model.record(0).value(4).toString());
    ui->amount2->setText(model.record(1).value(4).toString());
    ui->amount3->setText(model.record(2).value(4).toString());
    ui->amount4->setText(model.record(3).value(4).toString());
    ui->amount5->setText(model.record(4).value(4).toString());
}

search::search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    this->curr=0;
    this->carry=5;
    ui->currnum->setText(QString::number(this->curr+1));
    dbhandler* d=dbhandler::getInstance();
    bool ret=d->connect("localhost","imarket","root","123456");
    if(ret)
    {
        this->print();
    }
}

search::~search()
{
    delete ui;
}

void search::on_pushButton_clicked()
{
    this->curr--;
    ui->currnum->setText(QString::number(this->curr+1));

    this->print();

}

void search::on_pushButton_2_clicked()
{
    this->curr++;
    ui->currnum->setText(QString::number(this->curr+1));
    this->print();
}

void search::on_pushButton_3_clicked()
{
    qDebug()<<ui->lineEdit->text().toInt();
    this->curr=ui->lineEdit->text().toInt()-1;
    ui->currnum->setText(QString::number(this->curr));
    this->print();
}
