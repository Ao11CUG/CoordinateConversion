#include "CoordinateConversion.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CoordinateConversion w;
    w.show();
    return a.exec();
}
