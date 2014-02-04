/********************
* K-Auth project

* File : Kauth.cpp
* Summary : This is the controler-view of the project, the core of the application
* Required library : Qt v5.2
*
* Author : Maximilien DEFOURNE
* Licence : GPL v3 (see file LICENCE)
* Version : 0.5
* 
********************/

#include "Kauth.h"
#include "ui_mainwindow.h"


/*Construct the application*/
Kauth::Kauth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sticon(new QSystemTrayIcon(this))
{
    ui->setupUi(this);

    try{
        ssl.initPathOpenSSL();
        ui->sslPathButton->hide();
        ui->openButton->setEnabled(true);
    }catch(QString const& e){
        showMessageError(e);
    }
}

/*Destructor*/
Kauth::~Kauth()
{
    delete ui;
    delete sticon;
}

/***
* initSysTray() is a public function
* Load the programm into the Systray of the OS
* Pre-condition : a private key is load
* Return void
***/
void Kauth::initSysTray(){

    //Menu settings
    QMenu* stmenu = new QMenu(this);

    QAction *signerPressePapier = new QAction("Signer le presse-papier",this);
    QObject::connect(signerPressePapier, SIGNAL(triggered()), this, SLOT(signerPressePapier()));

    QAction *quitter = new QAction("Quitter KAuth",this);
    QObject::connect(quitter, SIGNAL(triggered()), this, SLOT(close()));

    stmenu->addAction(signerPressePapier);
    stmenu->addSeparator();
    stmenu->addAction(quitter);

    sticon->setContextMenu(stmenu);

    sticon->setIcon(QIcon(":/icones/systray.png"));


    //Message and show
    sticon->setVisible(true);
    sticon->showMessage("Clef chargée", "Vous pouvez désormais signer depuis cette icône");
    sticon->show();
}


/***
* on_openButton_clicked() is a private slot (see Qt signal/slot)
* Trigger : this function will be call automatically when the button "openButton" is clicked
* Open a FileDialog (Qt) and check if the file is a valid private key. If yes the application is minimzed in the SysTray
* Return void
***/
void Kauth::on_openButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Ouvrir clef privée"));

    //If the user selected a file
    if(!s.isNull()){
        try{
            ssl.checkPrivateKey(s);

            //We hide the application, and manage it with the systray
            this->initSysTray();
            this->hide();

        }catch(QString const& e){
            showMessageError(e);
        }
    }
}


/***
* signerPressePapier() is a private slot (see Qt signal/slot)
* Trigger : Show an Qt error message with the 'e' string
* QString e : the error message
* Return void
***/
void Kauth::signerPressePapier()
{
    QClipboard *pressePapier = QApplication::clipboard();

    try{

        //We store the content of the clipboard
        QString data = pressePapier->text();
        if(data.isEmpty())
            throw QString("Le presse papier ne contient pas de texte");

        QString res = ssl.signer(data);
        pressePapier->setText(res);

    }catch(QString const& e){
        showMessageError(e);
    }
}

/***
* showMessageError() is a private function
* Show an Qt error message with the 'e' string
* QString e : the error message
* Return void
***/
void Kauth::showMessageError(QString e){
    if(this->isHidden())
        QApplication::setQuitOnLastWindowClosed(false);

    QMessageBox error(this);
    error.setText(e);
    error.setIcon(QMessageBox::Critical);
    error.exec();

    if(this->isHidden())
        QApplication::setQuitOnLastWindowClosed(true);
}

/***
* showMessageError() is a private function
* Show an Qt error message with the 'e' string
* QString e : the error message
* Return void
***/
void Kauth::on_sslPathButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Chemin vers openssl"));

    //If the user selected a file
    if(!s.isNull()){
        try{
            if(ssl.checkPathOpenSSL(s)){
                ssl.setPathOpenSSL(s);
                ui->sslPathButton->hide();
                ui->openButton->setEnabled(true);
            }else{
                throw QString("Executable invalid");
            }

        }catch(QString const& e){
            showMessageError(e);
        }
    }
}
