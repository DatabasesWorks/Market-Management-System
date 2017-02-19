#include "customerform.h"
#include "ui_customerform.h"

customerform::customerform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customerform)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
}

customerform::~customerform()
{
    delete ui;
}

void customerform::on_pushButton_4_clicked()
{
    //QPixmap pixmap(".resources/pic.jpg");
    ikarketmap *mp=new ikarketmap();
    mp->show();
}

void customerform::on_pushButton_clicked()
{
    customersearch *custsearch=new customersearch();
    custsearch->show();
}

void customerform::on_pushButton_2_clicked()
{
    custeval *eval=new custeval();
    eval->show();
}
