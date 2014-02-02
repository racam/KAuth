#include "include/Kauth.h"
#include "ui_mainwindow.h"

Kauth::Kauth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

Kauth::~Kauth()
{
    delete ui;
    delete sticon;
}

void Kauth::on_openButton_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, tr("Ouvrir clef privée"), "/home");
    try{
        ssl.open(s);
    }catch(QString const& e){
        QMessageBox error;
        error.setText(e);
        error.setIcon(QMessageBox::Critical);
        error.exec();
    }

    this->initSysTray();

}

void Kauth::initSysTray(){
    sticon = new QSystemTrayIcon(this);

    QMenu* stmenu = new QMenu(this);

    QAction* actTexte1 = new QAction("Signer le presse-papier",this);
    stmenu->addAction(actTexte1);

    sticon->setContextMenu(stmenu);

    sticon->setIcon(QIcon("img/icon-key.png"));
    sticon->setVisible(true);

    sticon->showMessage("Clef chargée", "Vous pouvez désormais signer depuis cette icône");
    sticon->show();
}
