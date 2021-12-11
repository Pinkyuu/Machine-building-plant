#include "mainwindow.h"
#include "authorization.h"
#include "ui_mainwindow.h"
#include "ui_authorization.h"
#include "registration.h"
#include "ui_registration.h"
#include "checkinfo.h"
#include "ui_checkinfo.h"
#include "infouser.h"
#include "ui_infouser.h"
#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"

#include "QDialog"
#include "QMessageBox"
#include "QRandomGenerator"
#include "QTableWidget"
#include "QTimer"

int role = 0;

mainwindow::mainwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindow)
{
    ui->setupUi(this);

    authorizationuser();

    ui->tableWidget->setRowCount(10);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget_2->setRowCount(4);
    ui->tableWidget_2->setColumnCount(2);
}

void mainwindow::closewindow()
{
    auto updateTimer = new QTimer;
        connect(updateTimer, SIGNAL(timeout()), this, SLOT(exit()));
        updateTimer->start();
}

void mainwindow::authorizationuser()
{
    QDialog *auth = new QDialog;
    Ui::authorization ui_authorization;
    ui_authorization.setupUi(auth);
    bool try_auth = false;
    bool try_reg = false;
    if (auth->exec() == QDialog::Accepted)
    {
        try_auth = true;
        QString login = ui_authorization.nameedit->text();
        QString password = ui_authorization.passedit->text();
    } else
    {
        try_reg = true;
        QDialog *reg = new QDialog;
        Ui::registration ui_registration;
        ui_registration.setupUi(reg);
        if (reg->exec() == QDialog::Accepted)
        {
            QString login = ui_registration.nameedit->text();
            QString password = ui_registration.passedit->text();
        }
    }
    if (try_reg)
    {
        authorizationuser();
    }
    if (try_auth)
    {
        if (role == 0)
        {
            QMessageBox::information(0, 0, "You'r succeful authorisation.");
        }
        else if (role > 0)
        {
            QMessageBox::information(0, 0, "You'r succeful authorisation.");
            mainwindowadmin *mma = new mainwindowadmin;
            mma->show();
            closewindow();
        }
    }

}

mainwindow::~mainwindow()
{
    delete ui;
}

void mainwindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QDialog *check = new QDialog;
    Ui::checkinfo ui_checkinfo;
    ui_checkinfo.setupUi(check);
    check->exec();
}


void mainwindow::on_tableWidget_2_cellDoubleClicked(int row, int column)
{
    QDialog *infous = new QDialog;
    Ui::infouser ui_infouser;
    ui_infouser.setupUi(infous);
    infous->exec();
}

void mainwindow::exit()
{
    this->close();
}

