#ifndef KAUTH_H
#define KAUTH_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>

#include "OpenSSL.h"

namespace Ui {
    class MainWindow;
}

class Kauth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kauth(QWidget *parent = 0);
    ~Kauth();

    void initSysTray();

private slots:
    void on_openButton_clicked();
    void signerPressePapier();

private:
    Ui::MainWindow *ui;
    OpenSSL ssl;
    QSystemTrayIcon *sticon;

};

#endif // KAUTH_H
