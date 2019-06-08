#include "dbservices.h"

#include <QString>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QVariant>
#include <QDateTime>
#include <QTime>
#include <vector>
#include "relfechacaixa.h"
#include "totalcardsales.h"
#include "cashmovement.h"

DbServices::DbServices()
{

}

std::vector<RelFechaCaixa> * DbServices::reports()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/ramiro/workspace/verificacao-caixa/caixa.sqlite");
    if ( !db.open() )
    {
        qDebug() << "Erro ao abrir o banco" << db.lastError().text();
    }

    std::vector<RelFechaCaixa> * result = new std::vector<RelFechaCaixa>();
    {
        QSqlQuery query;
        query.exec(
                    "SELECT r.id, r.periodInit, r.periodEnd, r.cashier"
                    ", r.bills2, r.bills5, r.bills10, r.bills20, r.bills50, r.bills100"
                    ", r.cents1, r.cents5, r.cents10, r.cents25, r.cents50, r.cents100"
                    ", r.totalSales"
                    ", COALESCE(ro.totalCash, 0) as cashPreviousPeriod"
                    ", r.notes"
                    " FROM CASHFLOW_REPORT r"
                    " LEFT JOIN CASHFLOW_REPORT ro ON r.previousPeriodId = ro.id"
                    " ORDER BY r.periodInit DESC, r.periodEnd DESC"
                    " LIMIT 30");

        while ( query.next() )
        {
            RelFechaCaixa r( query.value("id").toInt(), query.value("cashPreviousPeriod").toDouble() );

            r.period_init = QDateTime::fromMSecsSinceEpoch( query.value("periodInit").toInt() );
            r.period_end = QDateTime::fromMSecsSinceEpoch( query.value("periodEnd").toInt() );

            r.cashier = query.value("cashier").toString();

            r.cash.set2Bills  ( query.value("bills2").toInt() );
            r.cash.set5Bills  ( query.value("bills5").toInt() );
            r.cash.set10Bills ( query.value("bills10").toInt() );
            r.cash.set20Bills ( query.value("bills20").toInt() );
            r.cash.set50Bills ( query.value("bills50").toInt() );
            r.cash.set100Bills( query.value("bills100").toInt() );

            r.cash.set1Cents  ( query.value("cents1").toInt() );
            r.cash.set5Cents  ( query.value("cents5").toInt() );
            r.cash.set10Cents ( query.value("cents10").toInt() );
            r.cash.set25Cents ( query.value("cents25").toInt() );
            r.cash.set50Cents ( query.value("cents50").toInt() );
            r.cash.set100Cents( query.value("cents100").toInt() );

            r.total_sales = query.value("totalSales").toDouble();

            r.notes = query.value("notes").toString();

            result->push_back(r);
        }
    }

    for (std::vector<RelFechaCaixa>::iterator it = result->begin(); it != result->end(); it++)
    {
        QSqlQuery query;
        query.prepare(
                    "SELECT flagAndMode, machine, totalValue"
                    " FROM CARDS_REPORT"
                    " WHERE reportId = :id"
                    " ORDER BY flagAndMode, machine");
        query.bindValue(":id", it->getId());
        query.exec();
        while( query.next() )
        {
            TotalCardSales s (
                    static_cast<TotalCardSales::FlagAndMode>(query.value("flagAndMode").toInt()),
                    static_cast<TotalCardSales::Machine>(query.value("machine").toInt()),
                    query.value("totalValue").toDouble()
                );
            it->cards.push_back(s);
        }
    }

    for (std::vector<RelFechaCaixa>::iterator it = result->begin(); it != result->end(); it++)
    {
        QSqlQuery query;
        query.prepare("SELECT movementTime, responsible, amount, flow, description"
                      " FROM MOVEMENT "
                      " WHERE reportId = :id "
                      " ORDER BY movementTime, responsible, amount");
        query.bindValue(":id", it->getId());
        query.exec();
        while( query.next() )
        {
            CashMovement m(
                        QTime::fromMSecsSinceStartOfDay( query.value("movementTime").toInt() ),
                        query.value("responsible").toString(),
                        query.value("amount").toDouble(),
                        static_cast<CashMovement::Flow>(query.value("flow").toInt()),
                        query.value("description").toString()
                    );

            it->movements.push_back(m);
        }
    }

    return result;
}

void DbServices::save(const RelFechaCaixa & report)
{

}
