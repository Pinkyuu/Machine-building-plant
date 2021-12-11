#ifndef INFOUSER_H
#define INFOUSER_H

#include <QDialog>

namespace Ui {
class infouser;
}

class infouser : public QDialog
{
    Q_OBJECT

public:
    explicit infouser(QWidget *parent = nullptr);
    ~infouser();

private:
    Ui::infouser *ui;
};

#endif // INFOUSER_H
