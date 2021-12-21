#include "authorization.h"
#include "ui_authorization.h"
#include "ui_registration.h"
#include "ui_mainwindow.h"
#include "ui_mainwindowadmin.h"
#include "mainwindow.h"
#include "mainwindowadmin.h"
#include "user.h"
#include <QMessageBox>
#include <QSaveFile>
#include <QFile>

authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    /*user u;
    u.setName("admin");
    u.setPassword("admin");
    u.setRole(1);
    u.setInfoUser("it's admin");
    m_users.push_back(u);

    user u2;
    u2.setName("user");
    u2.setPassword("user");
    u2.setRole(0);
    u2.setInfoUser("it's user");
    m_users.push_back(u2);
    saveuser();*/
    ui->setupUi(this);
    loaduser();
}

void authorization::open_mainwindow()
{
    QMessageBox::information(0, "BuildMachine-plant", QString("Вы успешно авторизированы."));
    if (m_auth_user.getRole() == 0)
    {
        mainwindow *mm = new mainwindow;
        mm->setUsers(m_users);
        mm->show();
        this->close();
    }
    else if (m_auth_user.getRole() == 1)
    {
        mainwindowadmin *mma = new mainwindowadmin;
        mma->setUsers(m_users);
        mma->show();
        this->close();
    }
}

authorization::~authorization()
{
    delete ui;
}



void authorization::on_Regbutton_clicked()
{
    QDialog *reg = new QDialog;
    Ui::registration ui_registration;
    ui_registration.setupUi(reg);
    user user_m;
    reg->show();
    if (reg->exec() == QDialog::Accepted)
    {
        QString login = ui_registration.nameedit->text();
        QString password = ui_registration.passedit->text();
        user_m.setName(login);
        user_m.setPassword(password);
        user_m.setRole(0);
        user_m.setInfoUser("clear");
        m_users.push_back(user_m);
        saveuser();
    }
}


void authorization::on_pushButton_clicked()
{
    bool try_auth = false; bool auth_succeful = false;
        try_auth = true;
        QString login = ui->nameedit->text();
        QString password = ui->passedit->text();
        for (size_t i = 0; i < m_users.size(); i++)
        {
            if ((m_users[i].getName() == login) && (m_users[i].getPassword() == password))
            {
                m_auth_user = m_users.at(i);
                auth_succeful = true;
                break;
            }
        }
    if (auth_succeful)
    {
        open_mainwindow();
    }
    else if (try_auth)
    {
        QMessageBox::information(0, "Machine Build", "Неверно введены фамилия и/или пароль.\nПопробуйте еще раз.");

    }
}

void authorization::saveuser()
{
    QSaveFile outf("user.tnb");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_users.size(); i++)
    {
            ost << m_users[i];
    }
    outf.commit();
}

void authorization::loaduser()
{
    QFile inf("user.tnb");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_users.clear();
    while (!ist.atEnd())
    {
        user u;
        ist >> u;
        m_users.push_back(u);
    }
}

