#include "secondwin.h"
#include "finalwindow.h"
#include "testone.h"
#include "ui_secondwin.h"
#include <QMessageBox>
secondWin::secondWin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondWin)
{
    ui->setupUi(this);
}

secondWin::~secondWin()
{
    delete ui;
}

void secondWin::on_pushButton_clicked()
{
    TestOne conn;
    QString uName , lName, contact ;
    uName = ui -> lineEdit_name -> text() ;
    lName = ui -> lineEdit_lastname -> text() ;
    contact = ui -> lineEdit_contact -> text() ;

    if(!conn.connOpen()){
        qDebug() << "Not Connected";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into data (name, surname, contact) values ('"+uName+"','"+lName+"','"+contact+"') ");

        if(qry.exec())
    {
        QMessageBox::critical(this,tr("Response Window"), tr ("Data Save Successfully")) ;
        conn.connClose();
    }
        else{
        QMessageBox::critical(this,tr("Error::"), qry.lastError().text()) ;
        }
}


void secondWin::on_pushButton_update_clicked()
{
        TestOne conn;
        QString uName , lName, contact ,id ;
        id = ui -> lineEdit_id -> text() ;
        uName = ui -> lineEdit_name -> text() ;
        lName = ui -> lineEdit_lastname -> text() ;
        contact = ui -> lineEdit_contact -> text() ;

        if(!conn.connOpen()){
        qDebug() << "Not Connected";
        return;
        }

        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("update data set name='"+uName+"', surname='"+lName+"', contact='"+contact+"' where id='"+id+"'");

        if(qry.exec())
        {
        QMessageBox::critical(this,tr("Response Window"), tr ("Data Update Successfully")) ;
        conn.connClose();
        }
        else{
        QMessageBox::critical(this,tr("Error::"), qry.lastError().text()) ;
        }
}


void secondWin::on_pushButton_delete_clicked()
{
        TestOne conn;
        QString uName , lName, contact ,id ;
        id = ui -> lineEdit_id -> text() ;
        uName = ui -> lineEdit_name -> text() ;
        lName = ui -> lineEdit_lastname -> text() ;
        contact = ui -> lineEdit_contact -> text() ;

        if(!conn.connOpen()){
        qDebug() << "Not Connected";
        return;
        }

        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("delete from data where id='"+id+"'");

        if(qry.exec())
        {
        QMessageBox::critical(this,tr("Response Window"), tr ("Data Delete Successfully")) ;
        conn.connClose();
        }
        else{
        QMessageBox::critical(this,tr("Error::"), qry.lastError().text()) ;
        }
}


void secondWin::on_pushButton_fetch_clicked()
{
        TestOne conn;
        QSqlQueryModel * modal=new QSqlQueryModel();
        conn.connOpen();

        QSqlQuery* qry=new QSqlQuery(conn.myfirstdb);
        qry->prepare("select * from data");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
//        this-> hide();
//        FinalWindow FinalWindow;
//        FinalWindow.setModal(modal);
//        FinalWindow.exec();
//        ui-> finaltable ->setmodal(modal);
        conn.connClose();
        qDebug()<<(modal->rowCount());

}


void secondWin::on_column_clicked()
{
    //column
        TestOne conn;
        QSqlQueryModel * modal=new QSqlQueryModel();
        conn.connOpen();

        QSqlQuery* qry=new QSqlQuery(conn.myfirstdb);
        qry->prepare("select name from data");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        conn.connClose();
        qDebug()<<(modal->rowCount());

}


void secondWin::on_fetchbyid_clicked()
{

        TestOne conn;
        QString id ;
        id = ui -> lineEdit_id -> text() ;


        QSqlQueryModel * modal=new QSqlQueryModel();
        conn.connOpen();

        QSqlQuery* qry=new QSqlQuery(conn.myfirstdb);
        qry->prepare("SELECT * FROM DATA WHERE id='"+id+"'");
        qry->exec();
        modal->setQuery(*qry);
        ui->tableView->setModel(modal);
        conn.connClose();
        qDebug()<<(modal->rowCount());
}

