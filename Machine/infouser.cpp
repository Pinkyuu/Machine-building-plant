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



void infouser::info(std::vector<user>* m_users_, int row, int column, int role)
{
     m_users = m_users_;
     ui->infoname->setText(m_users->at(row).getName());
     ui->inforole->setValue(m_users->at(row).getRole());
     ui->infoinfo->setText(m_users->at(row).getInfoUser());
     if (role == 0)
     {
         ui->infoname->setEnabled(false);
         ui->infoinfo->setEnabled(false);
         ui->inforole->setEnabled(false);
     }
     else if (column == 1)
     {
        ui->infoname->setEnabled(false);
        ui->infoinfo->setEnabled(false);
     }
     else if (column != 1)
     {
         ui->inforole->setEnabled(false);
     }
}



void infouser::on_buttonBox_accepted()
{
    QString name = ui->infoname->text();
    int role = ui->inforole->value();
    QString infoinfo = ui->infoinfo->text();
    user_m.setName(name);
    user_m.setRole(role);
    user_m.setInfoUser(infoinfo);
}

user infouser::getuser()
{
    return user_m;
}

