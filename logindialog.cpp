#include "logindialog.h"
#include "ui_logindialog.h"
#include <unistd.h>
#include <windows.h>
#include <QThread>
#include <qmessagebox.h>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnCancel_clicked()
{
    emit __loginFailed();
    close();
}

void LoginDialog::on_btnLogin_clicked()
{
    // login
    if(ui->leUsr->text() == usr && ui->lePass->text() == pass)
    {
        ui->stat->setText("login successful...");
        ui->stat->setStyleSheet("color : green");
        emit __loginSuccessful();
        close();
    }
    else
    {
//        emit __loginFailed();
        ui->stat->setText("wrong cridential!");
        ui->stat->setStyleSheet("color : red");
        QMessageBox::warning(this, tr("Warning"), tr("incorrect username or password."));
        return;
    }
}
