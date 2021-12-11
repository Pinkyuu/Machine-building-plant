#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "machine.h"

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
    void exit();
    void closewindow();
    void saveuser();
    void loaduser();
    /*void savemachine();
    void loadmachine();*/

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_tableWidget_2_cellDoubleClicked(int row, int column);

private:
    Ui::mainwindow *ui;
    std::vector<user> m_users;
    std::vector<machine> m_machine;
};

#endif // MAINWINDOW_H
