/********************
* K-Auth project

* File : Kauth.h
* Summary : This is the controler-view of the project, the core of the application
* Required library : Qt v5.2
*
* Author : Maximilien DEFOURNE
* Licence : GPL v3 (see file LICENCE)
* Version : 0.5
* 
********************/

#ifndef KAUTH_H
#define KAUTH_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QClipboard>

#include "OpenSSL.h"

//Namespace for ui file
namespace Ui {
    class MainWindow;
}

class Kauth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kauth(QWidget *parent = 0);
    ~Kauth();

    /***
    * initSysTray() function
    * Load the programm into the Systray of the OS
    * Pre-condition : a private key is load
    * Return void
    ***/
    void initSysTray();

private:

    /***
    * showMessageError() function
    * Load the programm into the Systray of the OS
    * Pre-condition : a private key is load
    * Return void
    ***/
    void showMessageError(QString e);

private slots:
    void on_openButton_clicked();
    void signerPressePapier();

private:
    Ui::MainWindow *ui;
    OpenSSL ssl;
    QSystemTrayIcon *sticon;

};

#endif // KAUTH_H
