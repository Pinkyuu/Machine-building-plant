#ifndef INFOUSER_H
#define INFOUSER_H

#include <QDialog>
#include "user.h"
#include <QStandardItemModel>

namespace Ui {
class infouser;
}

class infouser : public QDialog
{
    Q_OBJECT

public:
    explicit infouser(QWidget *parent = nullptr);
    ~infouser();
    void info(std::vector<user>*, int, int, int);
    user getuser();


private slots:
    void on_buttonBox_accepted();

private:
    Ui::infouser *ui;
    std::vector<user>* m_users;
    user user_m;
};

#endif // INFOUSER_H
