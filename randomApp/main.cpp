#include "randomApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    randomApp w;
    w.show();
    return a.exec();
}
