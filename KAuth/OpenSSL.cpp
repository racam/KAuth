#include "include/OpenSSL.h"

OpenSSL::OpenSSL()
{
}

OpenSSL::~OpenSSL()
{
}


void OpenSSL::open(QString s){
    QFile file(s);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw QString("Impossible d'ouvrir le fichier");

    /*QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        //process_line(line);
    }*/
}
