#include "mainwindow.h"

#include <QApplication>
#include "authorization.h"
#include "ui_authorization.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    authorization w;
    w.show();
    return a.exec();
}
