#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>

namespace Ui {
class mainwindowadmin;
}

class mainwindowadmin : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindowadmin(QWidget *parent = nullptr);
    ~mainwindowadmin();

private:
    Ui::mainwindowadmin *ui;
};

#endif // MAINWINDOWADMIN_H
