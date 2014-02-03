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

/*Initialisation*/
OpenSSL::OpenSSL(QObject *parent):
    openSSL(new QProcess(parent)),
    pathOpenSSL("bin/openssl.exe")
{
}

/*Destructor*/
OpenSSL::~OpenSSL()
{
    delete openSSL;
}

/***
* checkPrivateKey(QString s) is a public function
* Check if the file 's' is a valid private key
* QString s : the path to the private key
* Return void
***/
void OpenSSL::checkPrivateKey(QString s){

    //List of arguments to invok
    QStringList arguments;
    arguments << "rsa" << "-in" << s << "-check";

    openSSL->start(pathOpenSSL, arguments);
    if (!openSSL->waitForStarted())
        throw QString("Impossible de démarrer openssl");

    if (!openSSL->waitForFinished())
        throw QString("Impossible de finir openssl");

    //If nothing in standart output, the key is not valid
    if(openSSL->readAllStandardOutput().isEmpty()){
        throw QString("Clef privée invalide");
    }

    //set the path of the private key
    privateKey = s;
}

/***
* QString signer(QString data) is a public function
* Thanks to the privatekey, it will sign in base64 the 'data' SHA1's digest
* QString data : the data we want to sign
* Return QString : the data digest (SHA1) sign with the privateKey and encode in base64
***/
QString OpenSSL::signer(QString data){
    if(privateKey.isEmpty())
        throw QString("Clef privée manquante");

    QStringList arguments;
    arguments << "dgst" << "-sha1" << "-sign" << privateKey;
    openSSL->start(pathOpenSSL, arguments);

    if (!openSSL->waitForStarted())
        throw QString("Impossible de démarrer openssl");

    //We write the data into the standard input and then close it
    openSSL->write(data.toLatin1().data());
    openSSL->closeWriteChannel();

    if (!openSSL->waitForFinished())
        throw QString("Impossible de finir openssl");

    //We store the output data and encode it in base64
    QByteArray signature = openSSL->readAllStandardOutput().toBase64();


    if(signature.isEmpty())
        throw QString("Un problème est survenu durant la signature");

    return QString(signature);
}

