#include "ikarketmap.h"
#include "ui_ikarketmap.h"

ikarketmap::ikarketmap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ikarketmap)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    QPixmap pixmap("C:/Users/BK/Desktop/iMarket/resources/map.png");
    ui->label->setPixmap(pixmap);
    ui->label->setScaledContents(true);
    ui->label->show();
}

ikarketmap::~ikarketmap()
{
    delete ui;
}
