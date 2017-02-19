#include "authentication.h"
#include "ui_authentication.h"
authentication::authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentication)
{
    ui->setupUi(this);
}

authentication::~authentication()
{
    delete ui;
}

void authentication::on_buttonBox_accepted()
{
    //认证 如果正确则进行下一步
    //如果不正确 则退出
}
