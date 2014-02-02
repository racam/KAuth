#include "include/OpenSSL.h"

OpenSSL::OpenSSL(QObject *parent):
    openSSL(new QProcess(parent)),
    pathOpenSSL("bin/openssl.exe")
{
}

OpenSSL::~OpenSSL()
{
    delete openSSL;
}


void OpenSSL::checkPrivateKey(QString s){

    QStringList arguments;
    arguments << "rsa" << "-in" << s << "-check";

    openSSL->start(pathOpenSSL, arguments);
    if (!openSSL->waitForStarted(-1))
        throw QString("Impossible de démarrer openssl");

    if (!openSSL->waitForFinished())
        throw QString("Impossible de finir openssl");

    if(openSSL->readAllStandardOutput().isEmpty()){
        throw QString("Clef privée invalide");
    }
}
