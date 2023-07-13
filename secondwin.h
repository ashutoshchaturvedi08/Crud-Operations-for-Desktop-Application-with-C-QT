#ifndef SECONDWIN_H
#define SECONDWIN_H

#include <QDialog>

namespace Ui {
class secondWin;
}

class secondWin : public QDialog
{
    Q_OBJECT

public:
    explicit secondWin(QWidget *parent = nullptr);
    ~secondWin();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_update_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_fetch_clicked();

    void on_column_clicked();

    void on_fetchbyid_clicked();

private:
    Ui::secondWin *ui;
};

#endif // SECONDWIN_H
