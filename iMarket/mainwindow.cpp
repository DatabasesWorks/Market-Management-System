#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "authentication.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1050,650);
    this->setWindowTitle(QString::fromLocal8Bit("imarket"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_manager_clicked()
{
    //authentication *auth=new authentication();
    //auth->setModal(true);
    //auth->show();
    managerform *mager=new managerform();
    mager->show();
}

void MainWindow::on_customer_clicked()
{
    customerform *cust=new customerform();
    cust->show();
}
