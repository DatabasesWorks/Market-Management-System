#ifndef STOCKFROM_H
#define STOCKFROM_H

#include <QWidget>
#include "dbhandler.h"
#include <QMessageBox>
namespace Ui {
class stockfrom;
}

class stockfrom : public QWidget
{
    Q_OBJECT

public:
    explicit stockfrom(QWidget *parent = 0);
    ~stockfrom();

private slots:
    void on_pushButton_clicked();

private:
    Ui::stockfrom *ui;
};

#endif // STOCKFROM_H
