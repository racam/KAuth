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
