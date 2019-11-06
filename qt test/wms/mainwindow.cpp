#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include <QtDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString servername = "wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com";
    QString dbname = "legacywms";

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dsn = QString("DRIVER={SQL Native Client}; SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

   // QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  /*i think all this is necessary to connect the button to the database*/
   // db.setHostName("wms-database-3.cnuuwsy8dtiz.us-west-1.rds.amazonaws.com");      /*i think this is what the default was set to when i created my database*/
   // db.setPort(3306);
   // db.setDatabaseName("legacywms");    /*this is what i named my database sewms -> software engineering warehous managemet system*/
   // db.setUserName("root");         /*this is what i set the user name to*/
   // db.setPassword("samuraiedge");  /*this is the silly password i chose*/

    if(db.open())   /*this will check if the database is connected and running*/
    {
        QMessageBox::information(this, "Connection", "Database Connected Successfully");
    }
    else
    {
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected");
    }
}
