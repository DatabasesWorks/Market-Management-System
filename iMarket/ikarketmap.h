#ifndef IKARKETMAP_H
#define IKARKETMAP_H

#include <QWidget>
#include <QPixmap>
namespace Ui {
class ikarketmap;
}

class ikarketmap : public QWidget
{
    Q_OBJECT

public:
    explicit ikarketmap(QWidget *parent = 0);
    ~ikarketmap();

private:
    Ui::ikarketmap *ui;
};

#endif // IKARKETMAP_H
