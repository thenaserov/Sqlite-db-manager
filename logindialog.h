#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_btnCancel_clicked();
    void on_btnLogin_clicked();

private:
    Ui::LoginDialog *ui;
    QString usr = "a";
    QString pass = "a";

signals:
    void __loginSuccessful();
    void __loginFailed();
};

#endif // LOGINDIALOG_H
