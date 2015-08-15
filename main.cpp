#include "ornaments.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ornaments w;
    w.show();

    return a.exec();
}
