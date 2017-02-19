#ifndef CUSTEVAL_H
#define CUSTEVAL_H

#include <QWidget>
#include <QDebug>
#include "dbhandler.h"
#include <QSqlQuery>
#include <QMessageBox>
namespace Ui {
class custeval;
}

class custeval : public QWidget
{
    Q_OBJECT

public:
    explicit custeval(QWidget *parent = 0);
    ~custeval();

private slots:
    void on_pushButton_clicked();

private:
    Ui::custeval *ui;
};

#endif // CUSTEVAL_H
