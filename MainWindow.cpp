#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <logindialog.h>
#include <qlineedit.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Nahid Database viewer - V 1.5");
//    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
//    _ld = new LoginDialog;
//    connect(_ld, SIGNAL(__loginSuccessful()), this, SLOT(OnLoginSuccessful()));
//    connect(_ld, SIGNAL(__loginFailed()), this, SLOT(OnLoginFailed()));
//    connect();
//    _ld->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDB()
{
    setDatabase();
    setModel();
    setTable();
//    this->resize(ui->tableView->width(), ui->tableView->height());

}

void MainWindow::selectFileDB()
{
    _fileName = QFileDialog::getOpenFileName(this,tr("Select a sqlite DB"), "", tr(""));
    // here do the table name handling
    setDatabase();
    // pass the list of all tables avalable
    foreach(QString tableName, _db.tables())
    {
        _tableNames.append(tableName);
    }
    // here I might wanna define a new method for getting the table name from user cause I really think that won't happen only here!
    getTableNamesFromUser();
    openDB();
    setTablesNames();
}

void MainWindow::setModel()
{
    QSqlTableModel *model = new QSqlTableModel(ui->tableView, _db);
    _model = model;
//    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    _model->setEditStrategy(QSqlTableModel::OnFieldChange);
    _model->setTable(ui->lvTablesNames->currentIndex().data().toString()); // so static
    _model->select();
    //    _model->setHeaderData();
}

void MainWindow::setTable()
{
    ui->tableView->setModel(_model);
    ui->tableView->setGridStyle(Qt::SolidLine);
    ui->tableView->resizeRowsToContents();
    ui->tableView->resizeColumnsToContents();
//    _currentTableName
}

void MainWindow::setDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    _db = db;
    // code to get the path from our user
    _db.setDatabaseName(_fileName);
    if (!_db.open())
    {
         QMessageBox::warning(this, tr("Unable to open database"), tr("An error occurred while " "opening the connection: ") + _db.lastError().text());
    }
}

void MainWindow::getTableNamesFromUser()
{

}

void MainWindow::setTablesNames()
{
    QList<QString> _tablesList = _db.tables();
    _tableNamesModel->setStringList(_tablesList);
    ui->lvTablesNames->setModel(_tableNamesModel);
}

void MainWindow::OnLoginSuccessful()
{
//    this->resize(ui->tableView->width(), ui->tableView->height());
}

void MainWindow::OnLoginFailed()
{
    // show error message
    _ld->close();
    close();
}

void MainWindow::terminate()
{
    close();
}




void MainWindow::on_btnExit_clicked()
{
    close();
}

void MainWindow::on_btnAdd_clicked()
{
    setModel();
}

void MainWindow::on_btnDelete_clicked()
{

}


void MainWindow::on_btnOpenDB_clicked()
{
    selectFileDB();
}

void MainWindow::on_btnShowTable_clicked()
{
    _currentTableName = ui->lvTablesNames->currentIndex().data().toString();
    setModel();
    setTable();
}


