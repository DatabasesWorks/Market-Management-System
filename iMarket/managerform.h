#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QWidget>
#include "itemregister.h"
#include "search.h"
#include "stockfrom.h"
#include "paying.h"
namespace Ui {
class managerform;
}

class managerform : public QWidget
{
    Q_OBJECT

public:
    explicit managerform(QWidget *parent = 0);
    ~managerform();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::managerform *ui;
};

#endif // MANAGERFORM_H
