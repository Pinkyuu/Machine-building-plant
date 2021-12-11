#include "adduser.h"
#include "ui_adduser.h"

adduser::adduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
}

adduser::~adduser()
{
    delete ui;
}
