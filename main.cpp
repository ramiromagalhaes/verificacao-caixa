#include "mainwindow.h"
#include <QApplication>

#include "relfechacaixa.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RelFechaCaixa *r = new RelFechaCaixa();
    r->load();

    MainWindow w;
    w.setModel(r);
    w.show();

    return a.exec();
}
