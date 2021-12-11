#ifndef SETROLE_H
#define SETROLE_H

#include <QDialog>

namespace Ui {
class setrole;
}

class setrole : public QDialog
{
    Q_OBJECT

public:
    explicit setrole(QWidget *parent = nullptr);
    ~setrole();

private:
    Ui::setrole *ui;
};

#endif // SETROLE_H
