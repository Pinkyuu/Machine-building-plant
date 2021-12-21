#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"
#include "checkinfo.h"
#include "ui_checkinfo.h"
#include "infouser.h"
#include "ui_infouser.h"
#include "ui_settings.h"
#include "settings.h"
#include "repair.h"
#include "ui_repair.h"

#include <QDialog>
#include <QSaveFile>
#include <QFile>



mainwindowadmin::mainwindowadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindowadmin)
{
    /*loadmachine();
    loadrepair();*/
    ui->setupUi(this);
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

void mainwindowadmin::setUsers(std::vector<user> m_users_)
{
    m_users = m_users_;
    on_pushButton_clicked();
}

mainwindowadmin::~mainwindowadmin()
{
    delete ui;
}

void mainwindowadmin::on_tableWidget_cellDoubleClicked(int row, int column)
{
    settings set;
    set.info(&m_machine, row, column, 1, &m_repairs);
    if (set.exec() == QDialog::Accepted)
    {
        machine temp = set.getmachine();
        m_machine[row].setName(temp.getName());
        m_machine[row].setMark(temp.getMark());
        m_machine[row].setDate(temp.getDate());
        m_machine[row].setType(temp.getType());
        m_machine[row].setCountry(temp.getCountry());
        savemachine();
        on_pushButton_clicked();
    }

}


void mainwindowadmin::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    infouser uf;
    uf.info(&m_users, row, column, 1);
    if (uf.exec() == QDialog::Accepted)
    {
        user temp = uf.getuser();
        m_users[row].setName(temp.getName());
        m_users[row].setRole(temp.getRole());
        m_users[row].setInfoUser(temp.getInfoUser());
        saveuser();
    }
    on_pushButton_clicked();
}

void mainwindowadmin::opensettings()
{
    QDialog *add = new QDialog;
    Ui::settings ui_settings;
    ui_settings.setupUi(add);
    machine machine_m;
    ui_settings.countedit->setEnabled(false);
    if (add->exec() == QDialog::Accepted)
    {
        QString name = ui_settings.nameedit->text();
        QString mark = ui_settings.markedit->text();
        QDate Date = ui_settings.dateedit->date();
        QString country = ui_settings.countryedit->text();
        QString type = ui_settings.typeedit->text();
        machine_m.setName(name);
        machine_m.setMark(mark);
        machine_m.setDate(Date);
        machine_m.setCountry(country);
        machine_m.setType(type);
        machine_m.setID(m_machine.size());
        m_machine.push_back(machine_m);
        savemachine();
    }
    on_pushButton_clicked();
}

void mainwindowadmin::openrepair()
{
    repair rep;
    rep.setRepairs(&m_repairs, &m_machine);
    rep.exec();
    std::vector<repairs> temp = rep.getrep();
    for (int i = 0; i < temp.size(); i++)
    {
        m_repairs.push_back(temp[i]);
        saverepair();
    }
}


void mainwindowadmin::on_pushButton_clicked()
{
    ui->tableWidget->setRowCount(m_machine.size());
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget_2->setRowCount(m_users.size());
    ui->tableWidget_2->setColumnCount(3);

    for (int i = 0; i < m_users.size(); i ++)
    {
        QTableWidgetItem *usr = new QTableWidgetItem(tr("%1").arg(m_users[i].getName()));
        QTableWidgetItem *rle = new QTableWidgetItem(tr("%1").arg(m_users[i].getRole()));
        QTableWidgetItem *inf = new QTableWidgetItem(tr("%1").arg(m_users[i].getInfoUser()));
        ui->tableWidget_2->setItem(i, 0, usr);
        ui->tableWidget_2->setItem(i, 1, rle);
        ui->tableWidget_2->setItem(i, 2, inf);
    }
    for (int i = 0; i<m_machine.size(); i++)
    {
        QTableWidgetItem *nme = new QTableWidgetItem(tr("%1").arg(m_machine[i].getName()));
        QTableWidgetItem *cntry = new QTableWidgetItem(tr("%1").arg(m_machine[i].getCountry()));
        QTableWidgetItem *mrk = new QTableWidgetItem(tr("%1").arg(m_machine[i].getMark()));
        QTableWidgetItem *tpe = new QTableWidgetItem(tr("%1").arg(m_machine[i].getType()));
        QTableWidgetItem *id = new QTableWidgetItem(tr("%1").arg(m_machine[i].getID()));
        ui->tableWidget->setItem(i, 0, nme);
        ui->tableWidget->setItem(i, 1, cntry);
        ui->tableWidget->setItem(i, 2, tpe);
        ui->tableWidget->setItem(i, 3, mrk);
        ui->tableWidget->setItem(i, 4, id);

    }
}

void mainwindowadmin::saveuser()
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

void mainwindowadmin::savemachine()
{
    QSaveFile outf("machine.tnb");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_machine.size(); i++)
    {
        ost << m_machine[i];
    }
    outf.commit();
}

void mainwindowadmin::saverepair()
{
    QSaveFile outf("repairs.tnb");
    outf.open(QIODevice::WriteOnly);
    QDataStream ost(&outf);
    for (size_t i = 0; i < m_repairs.size(); i++)
    {
        ost << m_repairs[i];
    }
    outf.commit();
}

void mainwindowadmin::loadmachine()
{
    QFile inf("machine.tnb");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_machine.clear();
    while (!ist.atEnd())
    {
        machine u;
        ist >> u;
        m_machine.push_back(u);
    }
}

void mainwindowadmin::loadrepair()
{
    QFile inf("repairs.tnb");
    inf.open(QIODevice::ReadOnly);
    QDataStream ist(&inf);
    m_repairs.clear();
    while (!ist.atEnd())
    {
        repairs u;
        ist >> u;
        m_repairs.push_back(u);
    }
}
