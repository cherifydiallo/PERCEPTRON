#include "charger.h"
#include "ui_charger.h"

charger::charger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::charger)
{
    ui->setupUi(this);
    ok=0;

}

charger::~charger()
{
    delete ui;
}


void charger::on_pushButton_clicked()
{
  QEventLoop unepause;
  int i=0;




  while(i<=100){

   QTimer::singleShot (400, &unepause, SLOT (quit ()));

    ui->progressBar->setValue(i);
     unepause.exec();
  i=i+20;
  }
  this->close();
  QMessageBox::information(this, "Chargement", "EFFECTUE AVEC SUCCES");
  ok=1;
  ui->progressBar->setValue(0);


}


int charger::est_charger()
{
    return ok;
}

void charger::vider()
{
    ok=0;


}


