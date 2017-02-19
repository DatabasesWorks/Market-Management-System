#ifndef ITEMREGISTER_H
#define ITEMREGISTER_H

#include <QWidget>
#include "dbhandler.h"
#include <QtSql>
#include <QSqlQuery>
#include <QString>
#include <QMessageBox>
namespace Ui {
class itemregister;
}

class itemregister : public QWidget
{
    Q_OBJECT

public:
    explicit itemregister(QWidget *parent = 0);
    ~itemregister();

private slots:
    void on_pushButton_clicked();

private:
    Ui::itemregister *ui;
};

#endif // ITEMREGISTER_H
