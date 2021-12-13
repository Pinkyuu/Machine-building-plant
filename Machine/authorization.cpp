#include "authorization.h"
#include "ui_authorization.h"
#include "registration.h"
#include "ui_registration.h"
#include "registration.h"

authorization::authorization(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authorization)
{
    ui->setupUi(this);
}

authorization::~authorization()
{
    delete ui;
}


