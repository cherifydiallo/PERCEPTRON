#include "verifie.h"
#include "ui_verifie.h"

verifie::verifie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verifie)
{
    ui->setupUi(this);
    x0=x1=x2=0;
    good=0;
}

verifie::~verifie()
{
    delete ui;
}

float verifie::valeur0()
{
    return x0;
}

float verifie::valeur1()
{
    return x1;
}

float verifie::valeur2()
{
    return x2;
}

int verifie::est_good()
{
    return good;
}

void verifie::on_buttonBox_accepted()
{
       QString val1=ui->lineEdit_1->text();
       QString val2=ui->lineEdit_2->text();
       QString val3=ui->lineEdit_3->text();


       int r;

     bool ok1,ok2,ok3;
       if((val1!=NULL)&&(val2!=NULL)&&(val3!=NULL))
           {

             x0=val1.toFloat(&ok1);
             x1=val2.toFloat(&ok2);
             x2=val3.toFloat(&ok3);
             if(!ok1 || !ok2 || !ok3) {
                 QMessageBox::information(this, "Chargement", "VEUILLEZ REMPLIR AVEC DES VALEURS CORRECTES");

                                       }
            else     {
                     good=1;
                     }

           }else QMessageBox::information(this, "Chargement", "VEUILLEZ REMPLIR TOUS LES CHAMPS");

}
