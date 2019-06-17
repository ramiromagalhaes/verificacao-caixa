#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "relfechacaixa.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setModel(std::vector<RelFechaCaixa> * reports) {
        this->reports = reports;
        currentReport = this->reports->at(0);
    }

    void updateView();

    void addCashMovent();

private:
    Ui::MainWindow *ui;

    std::vector<RelFechaCaixa> * reports;
    RelFechaCaixa & currentReport;

    void updateTotalBills();
    void updateTotalCoins();
    void updateTotalCash();
    void updateCashMovements();

private slots:
    void spinR2Changed(int);
    void spinR5Changed(int);
    void spinR10Changed(int);
    void spinR20Changed(int);
    void spinR50Changed(int);
    void spinR100Changed(int);

    void spinR001Changed(int);
    void spinR005Changed(int);
    void spinR010Changed(int);
    void spinR025Changed(int);
    void spinR050Changed(int);
    void spinR1Changed(int);

    void handleAddCashMovent();
    void handleRemoveCashMovent();

    void handleSalesChanged(QString);

    void handleCardReportChanged(int, int);
    void handleNotesChanged();

    void handleSave();
    void handleFinish();
};

#endif // MAINWINDOW_H
