#ifndef SETROLE_H
#define SETROLE_H

#include <QDialog>
#include "user.h"
#include <QStandardItemModel>

namespace Ui {
class setrole;
}

class setrole : public QDialog
{
    Q_OBJECT

public:
    explicit setrole(QWidget *parent = nullptr);
    ~setrole();
    void setUsers(std::vector<user>*);
    void addtablewidget();


private:
    std::vector<user>* m_users;
    Ui::setrole *ui;
    QStandardItemModel *tbl;
};

#endif // SETROLE_H
