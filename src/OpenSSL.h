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

    /*Construct & destructor*/
    OpenSSL(QObject *parent = 0);
    ~OpenSSL();

    /***
    * checkPrivateKey(QString s) is a public function
    * Check if the file 's' is a valid private key
    * QString s : the path to the private key
    * Return void
    ***/
    void checkPrivateKey(QString s);

    /***
    * QString signer(QString data) is a public function
    * Thanks to the privatekey, it will sign in base64 the 'data' SHA1's digest
    * QString data : the data we want to sign
    * Return QString : the data digest (SHA1) sign with the privateKey and encode in base64
    ***/
    QString signer(QString data);

    void initPathOpenSSL();

    bool checkPathOpenSSL(QString path);

    void setPathOpenSSL(QString p);

private:
    QProcess *openSSL;
    QString pathOpenSSL;
    QString pathToPrivateKey;
};

#endif // OPENSSL_H
