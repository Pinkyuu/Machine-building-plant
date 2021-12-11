#include "user.h"

user::user()
{

}

user::~user()
{

}

void user::setName(QString name_)
{
    name = name_;
}

QString &user::getName()
{
    return name;
}

void user::setPassword(QString Password_)
{
    password = Password_;
}

QString &user::getPassword()
{
    return password;
}

void user::setInfoUser(QString InfoUser_)
{
    infouser = InfoUser_;
}

QString &user::getInfoUser()
{
    return infouser;
}

void user::setRole(int role_)
{
    role = role_;
}

int user::getRole()
{
    return role;
}

void user::save(QDataStream &ost) const
{
    ost << name << password << infouser;
}

void user::load(QDataStream &ist)
{
    ist << name << password << infouser;
}