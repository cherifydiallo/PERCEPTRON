#include "donnees.h"
#include "ui_donnees.h"

donnees::donnees(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::donnees)
{
    ui->setupUi(this);
}

donnees::~donnees()
{
    delete ui;
}




void donnees::afficher()
{


}

void donnees::on_pushButton_clicked()
{
    this->close();
}
