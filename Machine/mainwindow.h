#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "user.h"
#include "machine.h"
#include "repairs.h"

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
    void exit();
    void closewindow();
    void setUsers(std::vector<user>);
    /*void savemachine();
    void loadmachine();*/

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);
    void on_tableWidget_2_cellDoubleClicked(int row, int column);

    void on_reload_clicked();

private:
    user m_auth_user;
    Ui::mainwindow *ui;
    std::vector<user> m_users;
    std::vector<machine> m_machine;
    std::vector<repairs> m_repairs;
};

#endif // MAINWINDOW_H
