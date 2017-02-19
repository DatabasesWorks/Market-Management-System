#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbhandler.h"
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include "managerform.h"
#include "customerform.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_manager_clicked();

    void on_customer_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
