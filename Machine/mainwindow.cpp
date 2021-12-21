#include "mainwindow.h"
#include "authorization.h"
#include "ui_mainwindow.h"
#include "ui_authorization.h"
#include "registration.h"
#include "ui_registration.h"
#include "infouser.h"
#include "ui_infouser.h"
#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"
#include "settings.h"

#include "QDialog"
#include "QMessageBox"
#include "QRandomGenerator"
#include "QTableWidget"
#include "QTimer"
#include <QFile>
#include <QSaveFile>

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    on_reload_clicked();
    repairs a;
    a.setID(0);
    a.setEnRepair(QDate::currentDate());
    a.setStRepair(QDate::currentDate());
    a.setType("Hard");
    m_repairs.push_back(a);
    machine b;
    b.setCountry("Russia");
    b.setDate(QDate::currentDate());
    b.setID(0);
    b.setMark("Pejo");
    b.setName("AutoBuild");
    b.setType("Hard");
    machine c;
    c.setCountry("USA");
    c.setDate(QDate::currentDate());
    c.setID(1);
    c.setMark("Lada");
    c.setName("ArmyBuild");
    c.setType("Hard");
    m_machine.push_back(b);
    m_machine.push_back(c);

}

void mainwindow::setUsers(std::vector<user> m_users_)
{
    m_users = m_users_;
    on_reload_clicked();
}

void mainwindow::closewindow()
{
    auto updateTimer = new QTimer;
        connect(updateTimer, SIGNAL(timeout()), this, SLOT(exit()));
        updateTimer->start();
}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    settings ci;
    ci.info(&m_machine, row, column, 0, &m_repairs);
    ci.exec();
}


void mainwindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    infouser uf;
    uf.info(&m_users, row, column, 0);
    uf.exec();
}

void mainwindow::exit()
{
    this->close();
}


void mainwindow::on_reload_clicked()
{
    ui->tableWidget->setRowCount(m_machine.size());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget_2->setRowCount(m_users.size());
    ui->tableWidget_2->setColumnCount(2);

    for (int i = 0; i < m_users.size(); i ++)
    {
        QTableWidgetItem *usr = new QTableWidgetItem(tr("%1").arg(m_users[i].getName()));
        QTableWidgetItem *rle = new QTableWidgetItem(tr("%1").arg(m_users[i].getRole()));
        ui->tableWidget_2->setItem(i, 0, usr);
        ui->tableWidget_2->setItem(i, 1, rle);
    }
    for (int i = 0; i<m_machine.size(); i++)
    {
        QTableWidgetItem *nme = new QTableWidgetItem(tr("%1").arg(m_machine[i].getName()));
        QTableWidgetItem *cntry = new QTableWidgetItem(tr("%1").arg(m_machine[i].getCountry()));
        QTableWidgetItem *mrk = new QTableWidgetItem(tr("%1").arg(m_machine[i].getMark()));
        QTableWidgetItem *tpe = new QTableWidgetItem(tr("%1").arg(m_machine[i].getType()));
        ui->tableWidget->setItem(i, 0, nme);
        ui->tableWidget->setItem(i, 1, cntry);
        ui->tableWidget->setItem(i, 2, tpe);
        ui->tableWidget->setItem(i, 3, mrk);

    }
}

