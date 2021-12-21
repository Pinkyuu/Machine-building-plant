#ifndef REPAIR_H
#define REPAIR_H

#include <QStandardItemModel>
#include <QDialog>
#include "repairs.h"
#include "machine.h"

namespace Ui {
class repair;
}

class repair : public QDialog
{
    Q_OBJECT

public:
    explicit repair(QWidget *parent = nullptr);
    ~repair();
    void setRepairs(std::vector<repairs>*, std::vector<machine>*);
    void addRows();
    void addColumns();
    void addRows_2(int);
    void addColumns_2();
    std::vector<repairs> getrep();


private slots:
    void on_machineview_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();


private:
    Ui::repair *ui;
    std::vector<repairs>* m_repairs;
    std::vector<machine>* m_machine;
    std::vector<repairs> repairs_m;
    QStandardItemModel *tbl;
};

#endif // REPAIR_H
