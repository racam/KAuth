#ifndef OPENSSL_H
#define OPENSSL_H

#include <QString>
#include <QFile>
#include <QTextStream>

class OpenSSL
{
public:
    OpenSSL();
    ~OpenSSL();

    void open(QString s);

private:

};

#endif // OPENSSL_H
