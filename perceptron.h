#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <iostream>
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QTimer>
#include <QEventLoop>
#include <QLabel>
#include <verifie.h>
#include <QDialog>


#define nbreentree 2
#define tailleentree 4

namespace Ui {
class Perceptron;
}

class Perceptron : public QDialog
{
    Q_OBJECT

public:
    explicit Perceptron(QWidget *parent = 0);
    ~Perceptron();



      void initialize_Wi(int);
      void initialize_c();
      void initialize_encore();
      void sortie();
      void affichage_donnees();
      void affichage_sortie();
      void verifions();

private slots:
      void on_pushButton_clicked();

private:
    Ui::Perceptron *ui;
    verifie *v;
    int entree;
    int taille_entree;
    float **tab;
    float **tab2;
    int fini;
};

#endif // PERCEPTRON_H
