#include "setrole.h"
#include "ui_setrole.h"
#include <QTableWidget>

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

void setrole::setUsers(std::vector<user>* m_users_)
{
    m_users = m_users_;
    addtablewidget();
}

void setrole::addtablewidget()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(3);
    tbl->setHorizontalHeaderLabels(QStringList() << "Пользователь" << "Роль" << "Информация");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(tbl);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    for (size_t i = 0; i < m_users->size(); i++)
    {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_users->at(i).getName()));
            if (m_users->at(i).getRole() == 1)
            standardItemsList.append(new QStandardItem("Администратор"));
            else
            standardItemsList.append(new QStandardItem("Пользователь"));
            standardItemsList.append(new QStandardItem(m_users->at(i).getInfoUser()));
            tbl->insertRow(tbl->rowCount(), standardItemsList);
    }
}

