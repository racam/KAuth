/********************
* K-Auth project

* File : OpenSSL.cpp
* Summary : This is a model that provice an interface with openssl.exe
* Required library : Qt v5.2
*
* Author : Maximilien DEFOURNE
* Licence : GPL v3 (see file LICENCE)
* Version : 0.5
* 
********************/


#include "OpenSSL.h"

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
    if (!openSSL->waitForStarted())
        throw QString("Impossible de démarrer openssl");

    if (!openSSL->waitForFinished())
        throw QString("Impossible de finir openssl");

    if(openSSL->readAllStandardOutput().isEmpty()){
        throw QString("Clef privée invalide");
    }

    privateKey = s;
}

/*Signer la string data en base 64*/
QString OpenSSL::signer(QString data){
    if(privateKey.isEmpty())
        throw QString("Clef privée manquante");

    QStringList arguments;
    arguments << "dgst" << "-sha1" << "-sign" << privateKey;
    openSSL->start(pathOpenSSL, arguments);

    if (!openSSL->waitForStarted())
        throw QString("Impossible de démarrer openssl");

    openSSL->write(data.toLatin1().data());
    openSSL->closeWriteChannel();

    if (!openSSL->waitForFinished())
        throw QString("Impossible de finir openssl");

    QByteArray signature = openSSL->readAllStandardOutput().toBase64();
    if(signature.isEmpty())
        throw QString("Un problème est survenu durant la signature");

    return QString(signature);
}

