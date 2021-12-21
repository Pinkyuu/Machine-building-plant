#ifndef REPAIRS_H
#define REPAIRS_H

#include <QString>
#include <QDate>

class repairs
{
public:
    repairs();
    ~repairs();
    void setID(int);
    int &getID();
    void setType(QString);
    QString &getType();
    void setStRepair(QDate);
    QDate &getStRepair();
    void setEnRepair(QDate);
    QDate &getEnRepair();
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    int ID;
    QString Type;
    QDate StRepair;
    QDate EnRepair;
};

inline QDataStream &operator<<(QDataStream &ost, const repairs &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, repairs &u)
{
    u.load(ist);
    return ist;
}


#endif // REPAIRS_H
