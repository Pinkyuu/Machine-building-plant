#include "repairs.h"

repairs::repairs()
{

}

repairs::~repairs()
{

}

void repairs::setID(int ID_)
{
    ID = ID_;
}

int &repairs::getID()
{
    return ID;
}

void repairs::setType(QString Type_)
{
    Type = Type_;
}

QString &repairs::getType()
{
    return Type;
}

void repairs::setStRepair(QDate StRepair_)
{
    StRepair = StRepair_;
}

QDate &repairs::getStRepair()
{
    return StRepair;
}

void repairs::setEnRepair(QDate EnRepair_)
{
    EnRepair = EnRepair_;
}

QDate &repairs::getEnRepair()
{
    return EnRepair;
}

void repairs::save(QDataStream &ost) const
{
    ost << QString("%1").arg(ID) << Type << StRepair << EnRepair;
}

void repairs::load(QDataStream &ist)
{
    QString tmp;
    ist << tmp << Type << StRepair << EnRepair;
    ID = tmp.toInt();
}
