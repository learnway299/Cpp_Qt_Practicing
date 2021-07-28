#include "serverdialog.h"
#include "clientdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ServerDialog w;
    ClientDialog c;
    w.show();
    c.show();
    return a.exec();
}
