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

#include "include/Kauth.h"
#include "ui_mainwindow.h"

Kauth::Kauth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    sticon(new QSystemTrayIcon(this))
{
    ui->setupUi(this);
}

Kauth::~Kauth()
{
    delete ui;
    delete sticon;
}

void Kauth::initSysTray(){

    QMenu* stmenu = new QMenu(this);

    QAction *signerPressePapier = new QAction("Signer le presse-papier",this);
    QAction *quitter = new QAction("Quitter KAuth",this);

    QObject::connect(signerPressePapier, SIGNAL(triggered()), this, SLOT(signerPressePapier()));
    QObject::connect(quitter, SIGNAL(triggered()), this, SLOT(close()));

    stmenu->addAction(signerPressePapier);
    stmenu->addSeparator();
    stmenu->addAction(quitter);

    sticon->setContextMenu(stmenu);

    sticon->setIcon(QIcon("img/icon-key.png"));
    sticon->setVisible(true);

    sticon->showMessage("Clef chargée", "Vous pouvez désormais signer depuis cette icône");
    sticon->show();
}


void Kauth::on_openButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Ouvrir clef privée"), "/home");
    if(!s.isNull()){
        try{
            ssl.checkPrivateKey(s);
            this->initSysTray();
            this->hide();

        }catch(QString const& e){
            showMessageError(e);
        }
    }
}


void Kauth::signerPressePapier()
{
    QClipboard *pressePapier = QApplication::clipboard();

    try{
        QString data = pressePapier->text();
        if(data.isEmpty())
            throw QString("Le presse papier ne contient pas de texte");

        QString res = ssl.signer(data);
        pressePapier->setText(res);

    }catch(QString const& e){
        showMessageError(e);
    }
}

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
