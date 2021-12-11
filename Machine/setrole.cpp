#include "setrole.h"
#include "ui_setrole.h"

setrole::setrole(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setrole)
{
    ui->setupUi(this);
}

setrole::~setrole()
{
    delete ui;
}
