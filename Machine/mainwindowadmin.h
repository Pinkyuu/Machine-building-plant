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

public slots:
    void opensettings();
    void opensetrole();
    void openrepair();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

private:
    Ui::mainwindowadmin *ui;
};

#endif // MAINWINDOWADMIN_H
