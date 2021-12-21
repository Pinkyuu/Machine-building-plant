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
    ost << QString("%1").arg(ID) << name << country << Date << type << mark;
}

void machine::load(QDataStream &ist)
{
    QString tmp;
    ist << tmp << name << country << Date << type << mark;
    ID = tmp.toInt();
}
