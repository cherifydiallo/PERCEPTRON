#include "perceptron.h"
#include "ui_perceptron.h"
#define SAMAFICHIER "entree.txt"

Perceptron::Perceptron(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Perceptron)
{
    ui->setupUi(this);
    v=NULL;
    fini=0;
    int i,j,nlu,ncolonne;
    //cout <<"APPEL DU CONSTRUCTEUR"<<endl;
    entree=nbreentree+1;
    taille_entree=tailleentree;
    tab=new float*[entree];
    tab2=new float*[entree+2];

    for(i=0;i<entree;i++) tab[i]=new float[taille_entree];
    for(i=0;i<entree+2;i++) tab2[i]=new float[taille_entree];
    for(j=0;j<taille_entree;j++) tab[0][j]=1;



    QString phrase;
    char *ligne;
    char *mot;

    nlu=0;
    ncolonne=0;
    QString chemin="D:/PERCEPTRON/entree.csv";
    QFile fichier(chemin);
    QTextStream flux(&fichier);
    if (fichier.open(QIODevice::ReadOnly | QIODevice::Text)){

         phrase=flux.readLine();


                                 while(nlu<taille_entree){
                                // fgets(ligne,200,fichier);
                                 phrase=flux.readLine();

                                     ncolonne=0;
                                     ligne=phrase.toLocal8Bit().data();
                                    for(i=0;i<strlen(ligne);i++) if(ligne[i]==',') ligne[i]='.';
                                 mot=strtok(ligne,";");
                                 while(mot!=NULL){
                                    ncolonne++;
                                    if(ncolonne==2) tab[1][nlu]=atof(mot);
                                    if(ncolonne==3) tab[2][nlu]=atof(mot);
                                     if(ncolonne==5) tab2[entree][nlu]=atof(mot);
                                     //if(ncolonne==2) cout<<tab[1][nlu]<<endl;
                                    mot=strtok(NULL,";");
                                                 }
                                    nlu++;
                                                   }
   fichier.close();
    }else printf("IMPOSSIBLE D'OUVRIR LE FICHIER");


}



Perceptron::~Perceptron()
{
    delete ui;
//cout<<"APPEL DU DESTRUCTEUR"<<endl;
if(tab){
     for(int i=0;i<entree;i++) delete tab[i];
       delete tab;
        }
if(tab2){
      for(int i=0;i<entree+2;i++) delete tab2[i];
       delete tab2;
        }
if(v) delete v;
}












void Perceptron::initialize_Wi(int nbre){
int i,o;
float som;
//INITIALISATION DE Wi(W1,W2,...)
if(nbre==0) for(int i=0;i<entree;i++) tab2[i][0]=1;
else{
     for(int i=0;i<entree;i++)
     tab2[i][0]=tab2[i][taille_entree-1]+(tab2[entree][taille_entree-1]-tab2[entree+1][taille_entree-1])*tab[i][taille_entree-1];
     }
som=0;
for(i=0;i<entree;i++) som=som+(tab[i][0]*tab2[i][0]);
if(som>0) o=1;
else o=0;
tab2[entree+1][0]=o;


}






void Perceptron::sortie(){


    int i,j,nbre,cas_nul,ok;
    float som,o;

    float val1,val2,val3;
    val1=val2=val3=0;
    QTableWidget* table = new QTableWidget(this);
    table->setColumnCount(entree+2);
    table->setRowCount(taille_entree);
    table->setGeometry(50,0,500,400);



   QTableWidgetItem *col0;
   for(i=0;i<entree+2;i++){
   if(i<entree) col0 = new QTableWidgetItem("W"+QString::number(i));
   else if(i==entree)  col0 = new QTableWidgetItem("C");
   else col0 = new QTableWidgetItem("O");
   col0->setForeground(Qt::blue);
   col0->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(i, col0);

   }

nbre=0;
initialize_Wi(nbre);
this->show();

   for (i=0;i<entree;i++){
         val1=tab2[i][0];
         QString  var=QString::number(val1);
         table->setItem(0,i,new QTableWidgetItem(var));
                          }



   for (j=0;j<taille_entree;j++){
         val1=tab2[entree][j];
         QString  var=QString::number(val1);
         table->setItem(j,entree,new QTableWidgetItem(var));
                          }
QEventLoop unepause;

   QTimer::singleShot (200, &unepause, SLOT (quit ()));
   unepause.exec();
   val1=tab2[entree+1][0];
   QString  var=QString::number(val1);
   table->setItem(0,entree+1,new QTableWidgetItem(var));

    //CALCUL SORTIE

ok=0;
while(ok==0){
initialize_Wi(nbre);
cas_nul=0;




for(j=1;j<taille_entree;j++){

            for(i=0;i<entree;i++){
                            tab2[i][j]=tab2[i][j-1]+(tab2[entree][j-1]-tab2[entree+1][j-1])*tab[i][j-1];

                            QTimer::singleShot (200, &unepause, SLOT (quit ()));
                            unepause.exec();
                            val1=tab2[i][j];
                            QString  var=QString::number(val1);
                            table->setItem(j,i,new QTableWidgetItem(var));

                                }

            som=0;
            for(i=0;i<entree;i++) som=som+(tab[i][j]*tab2[i][j]);
            if(som>0) o=1;
            else o=0;
            tab2[entree+1][j]=o;

            QTimer::singleShot (200, &unepause, SLOT (quit ()));
            unepause.exec();
            val1=o;
            QString  var=QString::number(val1);
            table->setItem(j,entree+1,new QTableWidgetItem(var));


            if( (tab2[entree][j]-o)==0) cas_nul++;
            if(cas_nul==taille_entree-1) {
                               //          cout<<"A L ITERATION "<<nbre<<endl;
                                           ok=1;
                                          }


                            }

nbre++;

               }



fini=1;
 QMessageBox::information(this, "CHERIFY", "CALCUL EFFECTUE AVEC SUCCES");

}







void Perceptron::affichage_donnees(){

    int i,j;


    float val1,val2,val3;
    val1=val2=val3=0;
    QTableWidget* table = new QTableWidget(this);
    table->setColumnCount(entree);
    table->setRowCount(taille_entree);
    table->setGeometry(50,0,500,400);




   for(i=0;i<entree;i++){
   QTableWidgetItem *col0 = new QTableWidgetItem("X"+QString::number(i));
   col0->setForeground(Qt::blue);
   col0->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(i, col0);

   }



    for (i=0;i<entree;i++){
          for(j=0;j<taille_entree;j++){
          val1=tab[i][j];
          QString  var=QString::number(val1);
          table->setItem(j,i,new QTableWidgetItem(var));

                               }
                       }


this->show();



                                  }





void Perceptron::affichage_sortie(){

    int i;


    float val1,val2,val3;
    val1=val2=val3=0;
    QTableWidget* table = new QTableWidget(this);
    table->setColumnCount(entree);
    table->setRowCount(1);
    table->setGeometry(50,0,500,400);




   for(i=0;i<entree;i++){
   QTableWidgetItem *col0 = new QTableWidgetItem("W"+QString::number(i));
   col0->setForeground(Qt::blue);
   col0->setFont(QFont("Britannic Bold", 9));
   table->setHorizontalHeaderItem(i, col0);

   }


 if(fini==1){
    for (i=0;i<entree;i++){
          val1=tab2[i][taille_entree-1];
          QString  var=QString::number(val1);
          table->setItem(0,i,new QTableWidgetItem(var));
                        }
        }


this->show();


}

void Perceptron::verifions()
{

    if(fini==1){
        float x0,x1,x2,res;
                 v=new verifie();
                 v->exec();
                 if(v->est_good()==1) {
                     x0=v->valeur0();
                     x1=v->valeur1();
                     x2=v->valeur2();
                     res=x0*tab2[0][taille_entree-1]+x1*tab2[1][taille_entree-1]+x2*tab2[2][taille_entree-1];
                     if(res>0) QMessageBox::information(this, "RESULTAT", "1: DONC C'EST un Iris-versicolor");
                     else   QMessageBox::information(this, "RESULTAT", "0: DONC C'EST un Iris-setosa");

                     }
               }
}






void Perceptron::on_pushButton_clicked()
{
    this->close();
}
