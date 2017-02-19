#include "managerform.h"
#include "ui_managerform.h"

managerform::managerform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::managerform)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
}

managerform::~managerform()
{
    delete ui;
}

void managerform::on_pushButton_5_clicked()
{
    itemregister *regis=new itemregister();
    regis->show();
}

void managerform::on_pushButton_clicked()
{
    search *seh=new search();
    seh->show();
}

void managerform::on_pushButton_3_clicked()
{
    stockfrom *stock=new stockfrom();
    stock->show();
}

void managerform::on_pushButton_2_clicked()
{
    paying *py=new paying();
    py->show();
}
