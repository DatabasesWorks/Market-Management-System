#ifndef SEARCH_H
#define SEARCH_H

#include <QWidget>
#include <QDebug>
#include <QString>
#include <QSqlQuery>
#include "dbhandler.h"

namespace Ui {
class search;
}

class search : public QWidget
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = 0);
    ~search();
    int curr;
    int carry;
    void print();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H
