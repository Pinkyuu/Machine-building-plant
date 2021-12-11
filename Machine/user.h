#ifndef USER_H
#define USER_H

#include <QString>

class user
{
public:
    user();
    ~user();
    void setName(QString);
    QString &getName();
    void setPassword(QString);
    QString &getPassword();
    QString &getInfoUser();
    void setInfoUser(QString);
    void setRole(int);
    int getRole();
    void save(QDataStream &ost) const;
    void load(QDataStream &ist);
private:
    QString name;
    QString password;
    QString infouser;
    int role;
};

inline QDataStream &operator<<(QDataStream &ost, const user &u)
{
    u.save(ost);
    return ost;
}

inline QDataStream &operator>>(QDataStream &ist, user &u)
{
    u.load(ist);
    return ist;
}

#endif // USER_H
