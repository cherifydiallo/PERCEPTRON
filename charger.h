#ifndef CHARGER_H
#define CHARGER_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>
#include <QEventLoop>



namespace Ui {
class charger;
}

class charger : public QDialog
{
    Q_OBJECT

public:
    explicit charger(QWidget *parent = 0);
    ~charger();

       int est_charger();
       void vider();

private slots:
     void on_pushButton_clicked();


private:
    Ui::charger *ui;
    int ok;



};

#endif // CHARGER_H
