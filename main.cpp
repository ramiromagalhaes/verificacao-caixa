#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "dbservices.h"
#include "relfechacaixa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    DbServices db;
    std::vector<RelFechaCaixa> * reports = db.reports();
    qDebug() << "Total relatorios " << reports->size();
    RelFechaCaixa r = reports->at(0);

    MainWindow w;
    w.setModel(&r);
    w.updateView();
    w.show();

    return a.exec();
}
