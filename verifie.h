#ifndef VERIFIE_H
#define VERIFIE_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class verifie;
}

class verifie : public QDialog
{
    Q_OBJECT

public:
    explicit verifie(QWidget *parent = 0);
    ~verifie();
    float valeur0();
    float valeur1();
    float valeur2();
    int est_good();
private slots:
    void on_buttonBox_accepted();

private:
    Ui::verifie *ui;
    float x0,x1,x2;
    int good;
};

#endif // VERIFIE_H
