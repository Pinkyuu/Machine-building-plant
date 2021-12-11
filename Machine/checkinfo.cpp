#include "checkinfo.h"
#include "ui_checkinfo.h"

checkinfo::checkinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkinfo)
{
    ui->setupUi(this);
}

checkinfo::~checkinfo()
{
    delete ui;
}
