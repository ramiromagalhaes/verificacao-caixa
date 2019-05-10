#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <relfechacaixa.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    RelFechaCaixa cx;
    cx.load();

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
