/********************
* K-Auth project

* File : main.cpp
* Summary : The starting point of the sofware. Nothing else to say.
* Required library : Qt v5.2
*
* Author : Maximilien DEFOURNE
* Licence : GPL v3 (see file LICENCE)
* Version : 0.5
* 
********************/

#include "Kauth.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Kauth k;
    k.show();

    return a.exec();
}
