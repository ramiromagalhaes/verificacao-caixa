#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete model;
    delete ui;
}

void MainWindow::updateTotalBills()
{
    ui->labelTotalBills->setText( QString::number(model->cash.getTotalBills(), 'f', 2) );
    updateTotalCash();
}

void MainWindow::updateTotalCoins()
{
    ui->labelTotalCoins->setText( QString::number(model->cash.getTotalCoins(), 'f', 2) );
    updateTotalCash();
}

void MainWindow::updateTotalCash()
{
    ui->labelTotalCash->setText( QString::number(model->cash.getTotal(), 'f', 2) );
}

void MainWindow::spinR2Changed(int v)
{
    model->cash.set2Bills(v);
    updateTotalBills();
}

void MainWindow::spinR5Changed(int v)
{
    model->cash.set5Bills(v);
    updateTotalBills();
}

void MainWindow::spinR10Changed(int v)
{
    model->cash.set10Bills(v);
    updateTotalBills();
}

void MainWindow::spinR20Changed(int v)
{
    model->cash.set20Bills(v);
    updateTotalBills();
}

void MainWindow::spinR50Changed(int v)
{
    model->cash.set50Bills(v);
    updateTotalBills();
}

void MainWindow::spinR100Changed(int v)
{
    model->cash.set100Bills(v);
    updateTotalBills();
}

void MainWindow::spinR001Changed(int v)
{
    model->cash.set1Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR005Changed(int v)
{
    model->cash.set5Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR010Changed(int v)
{
    model->cash.set10Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR025Changed(int v)
{
    model->cash.set25Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR050Changed(int v)
{
    model->cash.set50Cents(v);
    updateTotalCoins();
}

void MainWindow::spinR1Changed(int v)
{
    model->cash.set100Cents(v);
    updateTotalCoins();
}
