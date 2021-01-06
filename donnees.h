#ifndef DONNEES_H
#define DONNEES_H
#include <QInputDialog>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDialog>



namespace Ui {
class donnees;
}

class donnees : public QDialog
{
    Q_OBJECT

public:
    explicit donnees(QWidget *parent = 0);
    ~donnees();
    void afficher();

private slots:
    void on_pushButton_clicked();

private:
    Ui::donnees *ui;

};

#endif // DONNEES_H
