#include "kmyloghandler.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KMyLogHandler w;
    w.show();
    return a.exec();
}
