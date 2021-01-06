#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ch=new charger(this);
    don=new Perceptron(this);
    ok=0;

}

MainWindow::~MainWindow()
{
    delete ui;
    if(ch) delete ch;
    if(don) delete don;
}

void MainWindow::on_actionQUIT_triggered()
{
    this->close();
}

void MainWindow::on_actionCHARGER_FICHIER_triggered()
{

ok=ch->est_charger();
if(ok==0) ch->exec();
else  QMessageBox::information(this, "Chargement", "DONNEES DEJA CHARGEES ,VEUILLEZ VIDER");
}



void MainWindow::on_actionMES_ENTREES_triggered()
{
ok=ch->est_charger();
if(ok==1){

   don->affichage_donnees();
//don->exec();
}else  QMessageBox::information(this, "Chargement", "VEUILLEZ CHARGEES DES DONNEES");

}

void MainWindow::on_actionVIDER_triggered()
{
    ch->vider();
    QMessageBox::information(this, "Chargement", "DONNEES VIDEES AVEC SUCCES");


}

void MainWindow::on_actionVOIR_triggered()
{

    ok=ch->est_charger();
    if(ok==1){
       don->sortie();

    }else  QMessageBox::information(this, "Chargement", "VEUILLEZ CHARGEES DES DONNEES");



}

void MainWindow::on_actionVOIR_2_triggered()
{
    ok=ch->est_charger();
    if(ok==1){
       don->affichage_sortie();

    }else  QMessageBox::information(this, "Chargement", "VEUILLEZ CHARGEES DES DONNEES");

}

void MainWindow::on_action_triggered()
{

    ok=ch->est_charger();
    if(ok==1){
       don->verifions();

    }else  QMessageBox::information(this, "Chargement", "VEUILLEZ CHARGEES DES DONNEES");


}
