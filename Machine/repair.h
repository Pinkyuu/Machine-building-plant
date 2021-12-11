#ifndef REPAIR_H
#define REPAIR_H

#include <QDialog>

namespace Ui {
class repair;
}

class repair : public QDialog
{
    Q_OBJECT

public:
    explicit repair(QWidget *parent = nullptr);
    ~repair();

private:
    Ui::repair *ui;
};

#endif // REPAIR_H
