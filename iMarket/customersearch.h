#ifndef CUSTOMERSEARCH_H
#define CUSTOMERSEARCH_H

#include <QWidget>
#include "dbhandler.h"
#include <QSqlQueryModel>
#include <Qstring>
namespace Ui {
class customersearch;
}

class customersearch : public QWidget
{
    Q_OBJECT

public:
    explicit customersearch(QWidget *parent = 0);
    ~customersearch();
    int curr;
    int carry;
    QString groupby;
    void print(QString a);

private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::customersearch *ui;
};

#endif // CUSTOMERSEARCH_H
