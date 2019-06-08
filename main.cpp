#include "mainwindow.h"
#include <QApplication>
#include "dbservices.h"
#include "relfechacaixa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    DbServices db;
    std::vector<RelFechaCaixa> * reports = db.reports();
    RelFechaCaixa r = reports->at(01);

    MainWindow w;
    w.setModel(&r);
    w.updateView();
    w.show();

    return a.exec();
}
