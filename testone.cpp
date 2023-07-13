#include "testone.h"
#include "ui_testone.h"

TestOne::TestOne(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestOne)
{
    ui->setupUi(this);
    myfirstdb=QSqlDatabase:: addDatabase("QSQLITE");
    myfirstdb.setDatabaseName("C:/Users/hp/Desktop/Sqlite_Database.db");

    if(!myfirstdb.open())
        ui -> label -> setText("can't connect to db");
    else
        ui -> label -> setText("connected to db");
}

TestOne::~TestOne()
{
    delete ui;
}


void TestOne::on_pushButton_clicked()
{
    QString userName , passWord ;
    userName = ui -> lineEdit_username -> text() ;
    passWord = ui -> lineEdit_password -> text() ;

     if(!myfirstdb.isOpen()){
        qDebug() << "Not Connected";
        return;
    }
    QSqlQuery qry;
    if (qry.exec(" select * from data where username='"+userName+"' and password='"+passWord+"'")){
        int count = 0   ;
        while (qry.next ()){
            count ++;
        }

        if (count == 1){
            ui -> label -> setText(" username and password is correct");
            this-> hide();
            secondWin secondWin;
            secondWin.setModal(true);
            secondWin.exec();


        }
        if (count > 1){
            ui -> label -> setText(" Duplicate username and password");}
        if (count < 1){
            ui -> label -> setText(" username and password is NOT correct");}

    }
}

