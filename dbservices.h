#ifndef DBSERVICES_H
#define DBSERVICES_H

#include <QtSql/QSqlDatabase>
#include <vector>
#include "relfechacaixa.h"

class DbServices
{
private:
    DbServices() {}

    static QSqlDatabase open();

public:
    static std::vector<RelFechaCaixa> * reports();

    static RelFechaCaixa create(QString cashier,
                                double previousPeriodCash = .0,
                                QDateTime periodInit = QDateTime::currentDateTime());

    static void save(const RelFechaCaixa & report);

    static void finish(const RelFechaCaixa & report);
};

#endif // DBSERVICES_H
