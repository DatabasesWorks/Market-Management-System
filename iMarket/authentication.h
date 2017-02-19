#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H
#include <QDebug>
#include <QDialog>
#include "dbhandler.h"
#include <QString>
namespace Ui {
class authentication;
}

class authentication : public QDialog
{
    Q_OBJECT

public:
    explicit authentication(QWidget *parent = 0);
    ~authentication();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::authentication *ui;
};

#endif // AUTHENTICATION_H
