#include "mainwindow.h"
#include <QApplication>

#include "relfechacaixa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RelFechaCaixa *r = new RelFechaCaixa(0, .0);
    r->load();

    MainWindow w;
    w.setModel(r);
    w.updateView();
    w.show();

    return a.exec();
}
