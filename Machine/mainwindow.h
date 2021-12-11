#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class mainwindow;
}

class mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

public slots:
    void authorizationuser();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

private:
    Ui::mainwindow *ui;
};

#endif // MAINWINDOW_H
