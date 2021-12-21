#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include "user.h"

namespace Ui {
class authorization;
}

class authorization : public QDialog
{
    Q_OBJECT

public:
    explicit authorization(QWidget *parent = nullptr);
    ~authorization();
private slots:

    void on_Regbutton_clicked();

    void on_pushButton_clicked();

public slots:
    void open_mainwindow();
    void saveuser();
    void loaduser();

private:
    Ui::authorization *ui;
    std::vector<user> m_users;
    user m_auth_user;
};

#endif // AUTHORIZATION_H
