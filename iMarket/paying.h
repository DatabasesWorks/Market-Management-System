#ifndef PAYING_H
#define PAYING_H

#include <QWidget>
#include "dbhandler.h"
#include <QMessageBox>
#include <QMap>
#include <QString>
#include <bits/stdc++.h>
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>
namespace Ui {
class paying;
}

class paying : public QWidget
{
    Q_OBJECT

public:
    explicit paying(QWidget *parent = 0);
    ~paying();
    QMap <QString,std::pair<int,float> > bill;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::paying *ui;
};

#endif // PAYING_H
