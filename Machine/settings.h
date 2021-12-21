#ifndef SETTINGS_H
#define SETTINGS_H

#include <QStandardItemModel>
#include <QDialog>
#include "machine.h"
#include "repairs.h"

namespace Ui {
class settings;
}

class settings : public QDialog
{
    Q_OBJECT

public:
    explicit settings(QWidget *parent = nullptr);
    ~settings();
    void info(std::vector<machine>* m_machine_, int, int, int, std::vector<repairs>* m_repairs_);
    machine getmachine();
    void addRows();
    void addColumns();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::settings *ui;
    std::vector<machine>* m_machine;
    std::vector<repairs>* m_repairs;
    machine machine_m;
    QStandardItemModel *tbl;
    int ROWs;
};

#endif // SETTINGS_H
