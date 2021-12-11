#ifndef CHECKINFO_H
#define CHECKINFO_H

#include <QDialog>

namespace Ui {
class checkinfo;
}

class checkinfo : public QDialog
{
    Q_OBJECT

public:
    explicit checkinfo(QWidget *parent = nullptr);
    ~checkinfo();

private:
    Ui::checkinfo *ui;
};

#endif // CHECKINFO_H
