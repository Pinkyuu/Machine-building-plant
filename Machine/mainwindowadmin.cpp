#include "mainwindowadmin.h"
#include "ui_mainwindowadmin.h"

mainwindowadmin::mainwindowadmin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainwindowadmin)
{
    ui->setupUi(this);
}

mainwindowadmin::~mainwindowadmin()
{
    delete ui;
}
