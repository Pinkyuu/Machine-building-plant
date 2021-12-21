#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::info(std::vector<machine>* m_machine_, int row, int column, int role, std::vector<repairs>* m_repairs_)
{
    m_machine = m_machine_;
    m_repairs = m_repairs_;
    ROWs = row;
    ui->nameedit->setText(m_machine->at(row).getName());
    ui->markedit->setText(m_machine->at(row).getMark());
    ui->dateedit->setDate(m_machine->at(row).getDate());
    ui->typeedit->setText(m_machine->at(row).getType());
    int count;
    for (int i = 0; i < m_repairs->size(); i++)
    {
        if (m_machine->at(row).getID() == m_repairs->at(i).getID())
        {
            count++;

        }
    }
    ui->countedit->setValue(count);
    ui->countryedit->setText(m_machine->at(row).getCountry());
    ui->countedit->setEnabled(false);
    if (role == 0)
    {
        ui->nameedit->setEnabled(false);
        ui->markedit->setEnabled(false);
        ui->dateedit->setEnabled(false);
        ui->typeedit->setEnabled(false);
        ui->countryedit->setEnabled(false);
    }
    addColumns();
    addRows();
}

void settings::on_buttonBox_accepted()
{
    QString name = ui->nameedit->text();
    QString mark = ui->markedit->text();
    QDate date = ui->dateedit->date();
    QString type = ui->typeedit->text();
    QString country = ui->countryedit->text();
    machine_m.setName(name);
    machine_m.setMark(mark);
    machine_m.setDate(date);
    machine_m.setType(type);
    machine_m.setCountry(country);
}

void settings::addColumns()
{
    tbl = new QStandardItemModel;
    tbl->setColumnCount(3);
    tbl->setHorizontalHeaderLabels(QStringList()  << "Тип ремонта" << "Начало ремонта" << "Конец ремонта");
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->setModel(tbl);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
}

void settings::addRows()
{
    for (size_t i = 0; i < m_repairs->size(); i++)
    {
    if (m_machine->at(ROWs).getID() == m_repairs->at(i).getID())
    {
        QList<QStandardItem *> standardItemsList;
        standardItemsList.append(new QStandardItem(m_repairs->at(i).getType()));
        standardItemsList.append(new QStandardItem(m_repairs->at(i).getStRepair().toString()));
        standardItemsList.append(new QStandardItem(m_repairs->at(i).getEnRepair().toString()));
        tbl->insertRow(tbl->rowCount(), standardItemsList);
    }
    }
}

machine settings::getmachine()
{
    return machine_m;
}
