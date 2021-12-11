#include "infouser.h"
#include "ui_infouser.h"

infouser::infouser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infouser)
{
    ui->setupUi(this);
}

infouser::~infouser()
{
    delete ui;
}
