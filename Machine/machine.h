#ifndef MACHINE_H
#define MACHINE_H

#include <QString>
#include <QDate>

class machine
{
public:
    machine();
    ~machine();
    void setID(int);
    int &getID();
    void setName(QString);
    QString &getName();
    void setCountry(QString);
    QString &getCountry();
    void setDate(QDate);
    QDate &getDate();
    void setType(QString);
    QString &getType();
    void setMark(QString);
    QString &getMark();
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    int ID;
    QString name;
    QString country;
    QDate Date;
    QString type;
    QString mark;
};

inline QDataStream &operator<<(QDataStream &ost, const machine &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, machine &u)
{
    u.load(ist);
    return ist;
}

#endif // MACHINE_H
