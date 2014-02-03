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

#ifndef OPENSSL_H
#define OPENSSL_H

#include <iostream>
#include <QString>
#include <QProcess>

class OpenSSL
{
public:
    OpenSSL(QObject *parent = 0);
    ~OpenSSL();

    void checkPrivateKey(QString s);
    QString signer(QString data);

private:
    QProcess *openSSL;
    QString pathOpenSSL;
    QString privateKey;
};

#endif // OPENSSL_H
