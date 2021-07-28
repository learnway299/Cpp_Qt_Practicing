//#include "widget.h"
#include "installwizard.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Widget w;
    InstallWizard w;
    w.show();
    return a.exec();
}
