#include "include/Kauth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Kauth k;
    k.show();

    return a.exec();
}
