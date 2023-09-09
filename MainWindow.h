#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QStandardItemModel>
#include "logindialog.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    LoginDialog *_ld = nullptr;
    QSqlTableModel *_model = nullptr;
    QSqlDatabase _db;
    QString _currentTableName = "";
    void openDB();
    QString _fileName = "";
    void selectFileDB();
    void setModel();
    void setTable();
    void setDatabase();
    QList<QString> _tableNames;
    void getTableNamesFromUser();
    QStringListModel *_tableNamesModel = new QStringListModel();
    void setTablesNames();

public slots:
    void OnLoginSuccessful();
    void OnLoginFailed();
    void terminate();


private slots:
    void on_btnExit_clicked();
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_btnOpenDB_clicked();
    void on_btnShowTable_clicked();
};
#endif // LOGIN_H
