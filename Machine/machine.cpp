#include "machine.h"

machine::machine()
{

}

machine::~machine()
{

}

void machine::setID(int ID_)
{
    ID = ID_;
}

int &machine::getID()
{
    return ID;
}

void machine::setName(QString name_)
{
    name = name_;
}

QString &machine::getName()
{
    return name;
}

void machine::setCountry(QString country_)
{
    country = country_;
}

QString &machine::getCountry()
{
    return country;
}

void machine::setDate(QDate Date_)
{
    Date = Date_;
}

QDate &machine::getDate()
{
    return Date;
}

void machine::setCount(int count_repair_)
{
    count_repair = count_repair_;
}

int &machine::getCount()
{
    return count_repair;
}

void machine::setType(QString type_)
{
    type = type_;
}

QString &machine::getType()
{
    return type;
}

void machine::setMark(QString mark_)
{
    mark = mark_;
}

QString &machine::getMark()
{
    return mark;
}

void machine::save(QDataStream &ost) const
{
    ost << ID << name << country << Date << count_repair << type << mark;
}

void machine::load(QDataStream &ist)
{
    ist << ID << name << country << Date << count_repair << type << mark;
}
