#include "repair.h"
#include "ui_repair.h"

repair::repair(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::repair)
{
    ui->setupUi(this);
}

repair::~repair()
{
    delete ui;
}
