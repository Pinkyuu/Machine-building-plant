#include "repair.h"
#include "ui_repair.h"
#include "repairs.h"

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





void repair::setRepairs(std::vector<repairs>* m_repairs_, std::vector<machine>* m_machine_)
{
    m_repairs = m_repairs_;
    m_machine = m_machine_;
    addColumns();
    addRows();


}

void repair::addColumns()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(5);
    tbl->setHorizontalHeaderLabels(QStringList() << "Название" << "Страна" << "Тип" << "Марка");
    ui->machineview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->machineview->setModel(tbl);
    ui->machineview->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->machineview->setSelectionMode(QAbstractItemView::SingleSelection);
}

void repair::addRows()
{
    for (size_t i = 0; i < m_machine->size(); i++)
    {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_machine->at(i).getName()));
            standardItemsList.append(new QStandardItem(m_machine->at(i).getCountry()));
            standardItemsList.append(new QStandardItem(m_machine->at(i).getType()));
            standardItemsList.append(new QStandardItem(m_machine->at(i).getMark()));
            tbl->insertRow(tbl->rowCount(), standardItemsList);
    }
}

void repair::addColumns_2()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(3);
    tbl->setHorizontalHeaderLabels(QStringList() << "Тип ремонта" << "Начало ремонта" << "Конец ремонта");
    ui->repairview->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->repairview->setModel(tbl);
    ui->repairview->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->repairview->setSelectionMode(QAbstractItemView::SingleSelection);
}

void repair::addRows_2(int ID)
{
    addColumns_2();
    for (size_t i = 0; i < m_repairs->size(); i++)
    {
        if (ID == m_repairs->at(i).getID())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(m_repairs->at(i).getType()));
            standardItemsList.append(new QStandardItem(m_repairs->at(i).getStRepair().toString()));
            standardItemsList.append(new QStandardItem(m_repairs->at(i).getEnRepair().toString()));
            tbl->insertRow(tbl->rowCount(), standardItemsList);
        }
    }
    for (size_t i = 0; i < repairs_m.size(); i++)
    {
        if (ID == repairs_m[i].getID())
        {
            QList<QStandardItem *> standardItemsList;
            standardItemsList.append(new QStandardItem(repairs_m[i].getType()));
            standardItemsList.append(new QStandardItem(repairs_m[i].getStRepair().toString()));
            standardItemsList.append(new QStandardItem(repairs_m[i].getEnRepair().toString()));
            tbl->insertRow(tbl->rowCount(), standardItemsList);
        }
    }
}




void repair::on_machineview_doubleClicked(const QModelIndex &index)
{
    int i = index.row();
    addRows_2(i);
}


void repair::on_pushButton_clicked()
{
    // Тест на пустой
    if (!ui->machineview->selectionModel()->hasSelection())
    {
        return;
    }
    QModelIndexList selection = ui->machineview->selectionModel()->selectedRows();
    QModelIndex index = selection.at(0);
    int i = index.row();
    QDate St = ui->dateTimeEdit->date();
    QDate En = ui->dateTimeEdit_2->date();
    QString Type = ui->lineEdit->text();
    repairs rep;
    rep.setID(i);
    rep.setStRepair(St);
    rep.setEnRepair(En);
    rep.setType(Type);
    repairs_m.push_back(rep);
    addRows_2(i);
}

std::vector<repairs> repair::getrep()
{
    return repairs_m;
}



