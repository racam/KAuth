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
    * initSysTray() is a public function
    * Load the programm into the Systray of the OS
    * Pre-condition : a private key is load
    * Return void
    ***/
    void initSysTray();

private:

    /***
    * showMessageError() is a private function
    * Show an Qt error message with the 'e' string
    * QString e : the error message
    * Return void
    ***/
    void showMessageError(QString e);

private slots:
    
    /***
    * on_openButton_clicked() is a private slot (see Qt signal/slot)
    * Trigger : this function will be call automatically when the button "openButton" is clicked
    * Open a FileDialog (Qt) and check if the file is a valid private key. If yes the application is minimzed in the SysTray
    * Return void
    ***/
    void on_openButton_clicked();

    /***
    * signerPressePapier() is a private slot (see Qt signal/slot)
    * Trigger : Show an Qt error message with the 'e' string
    * QString e : the error message
    * Return void
    ***/
    void signerPressePapier();

private:
    Ui::MainWindow *ui;
    OpenSSL ssl;
    QSystemTrayIcon *sticon;

};

#endif // KAUTH_H
