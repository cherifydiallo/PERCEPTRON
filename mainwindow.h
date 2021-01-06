#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "charger.h"
#include "perceptron.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQUIT_triggered();

    void on_actionCHARGER_FICHIER_triggered();

    void on_actionMES_ENTREES_triggered();

    void on_actionVIDER_triggered();

    void on_actionVOIR_triggered();

    void on_actionVOIR_2_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    charger *ch;
    Perceptron *don;
    int ok;

};

#endif // MAINWINDOW_H
