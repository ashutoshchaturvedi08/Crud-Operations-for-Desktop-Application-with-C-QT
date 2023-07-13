#include "testone.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestOne w;
    w.show();
    return a.exec();
}
