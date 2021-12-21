#ifndef MAINWINDOWADMIN_H
#define MAINWINDOWADMIN_H

#include <QMainWindow>
#include "user.h"
#include "machine.h"
#include "repairs.h"

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
    void openrepair();
    void setUsers(std::vector<user>);
    void saveuser();
    void savemachine();
    void saverepair();
    void loadmachine();
    void loadrepair();

private slots:
    void on_tableWidget_cellDoubleClicked(int row, int column);

    void on_tableWidget_2_cellDoubleClicked(int row, int column);

    void on_pushButton_clicked();

private:
    Ui::mainwindowadmin *ui;
    std::vector<user> m_users;
    std::vector<machine> m_machine;
    std::vector<repairs> m_repairs;
};

#endif // MAINWINDOWADMIN_H
