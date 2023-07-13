#ifndef TESTONE_H
#define TESTONE_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "secondwin.h"



QT_BEGIN_NAMESPACE
namespace Ui { class TestOne; }
QT_END_NAMESPACE

class TestOne : public QMainWindow
{
    Q_OBJECT


public:
       QSqlDatabase myfirstdb ;
    void connClose(){
        myfirstdb.close();
        myfirstdb.removeDatabase(QSqlDatabase::defaultConnection);

    }
    bool connOpen(){

        myfirstdb=QSqlDatabase:: addDatabase("QSQLITE");
        myfirstdb.setDatabaseName("C:/Users/hp/Desktop/Sqlite_Database.db");

        if(!myfirstdb.open()){
            qDebug()<<("can't connect to db");
            return false;}
        else{
           qDebug()<<("Connected to db");
            return true;}
    }




public:
    TestOne(QWidget *parent = nullptr);
    ~TestOne();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TestOne *ui;

};
#endif // TESTONE_H
