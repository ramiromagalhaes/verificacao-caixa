#include "mainwindow.h"
#include <QApplication>
#include "dbservices.h"
#include "relfechacaixa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::vector<RelFechaCaixa> * reports = DbServices::reports();

    MainWindow w;
    w.setModel(reports);
    w.updateView();
    w.show();

    return a.exec();
}
