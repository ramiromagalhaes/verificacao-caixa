#include "dbservices.h"

#include <QtSql/QSqlDatabase>

DbServices::DbServices()
{

}

std::vector<RelFechaCaixa> DbServices::reports()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("caixa.db");

    if ( !db.open() )
    {
       qDebug() << sdb.lastError().text();

    }
    else
    {
       qDebug() << "Database: connection ok";
    }

    QSqlQuery query;
    query.exec("SELECT ");
}

void DbServices::save(RelFechaCaixa report)
{

}
