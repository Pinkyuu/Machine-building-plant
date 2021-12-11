#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"
#include "checkinfo.h"
#include "ui_checkinfo.h"
#include "infouser.h"
#include "ui_infouser.h"
#include "ui_settings.h"
#include "settings.h"
#include "setrole.h"
#include "ui_setrole.h"
#include "repair.h"
#include "ui_repair.h"

#include <QDialog>

mainwindowadmin::mainwindowadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindowadmin)
{
    ui->setupUi(this);

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget_2->setRowCount(4);
    ui->tableWidget_2->setColumnCount(2);
}

mainwindowadmin::~mainwindowadmin()
{
    delete ui;
}

void mainwindowadmin::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QDialog *check = new QDialog;
    Ui::checkinfo ui_checkinfo;
    ui_checkinfo.setupUi(check);
    check->exec();
}


void mainwindowadmin::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    QDialog *infous = new QDialog;
    Ui::infouser ui_infouser;
    ui_infouser.setupUi(infous);
    infous->exec();
}

void mainwindowadmin::opensettings()
{
    QDialog *add = new QDialog;
    Ui::settings ui_settings;
    ui_settings.setupUi(add);
    add->exec();

}

void mainwindowadmin::opensetrole()
{
    QDialog *set = new QDialog;
    Ui::setrole ui_setrole;
    ui_setrole.setupUi(set);
    set->exec();
}

void mainwindowadmin::openrepair()
{
    QDialog *rep = new QDialog;
    Ui::repair ui_repair;
    ui_repair.setupUi(rep);
    rep->exec();
}

