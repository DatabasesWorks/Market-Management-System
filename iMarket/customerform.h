#ifndef CUSTOMERFORM_H
#define CUSTOMERFORM_H

#include <QWidget>
#include <QPixmap>
#include "ikarketmap.h"
#include "customersearch.h"
#include "custeval.h"
namespace Ui {
class customerform;
}

class customerform : public QWidget
{
    Q_OBJECT

public:
    explicit customerform(QWidget *parent = 0);
    ~customerform();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::customerform *ui;
};

#endif // CUSTOMERFORM_H
