#include "relfechacaixa.h"

void RelFechaCaixa::load()
{
    identifier = 1;

    period_init = QDateTime(QDate(2019, 5, 4), QTime(10, 0));
    period_end = QDateTime();

    cashier = QString("João");

    cash.load();

    movements.clear();
    /*
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,00), 100.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,10), 200.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,30), 300.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Depósito"), QTime(11,30), 600.10, CashMovement::Flow::inward) );
    */

    previous_period_cash = .0;
    total_sales = .0;

    cards.clear();
    cards.push_back( TotalCardSales(TotalCardSales::FlagAndMode::Amex,    TotalCardSales::Machine::TEF, 500.0) );
    cards.push_back( TotalCardSales(TotalCardSales::FlagAndMode::Visa,    TotalCardSales::Machine::TEF, 400.0) );
    cards.push_back( TotalCardSales(TotalCardSales::FlagAndMode::Elo,     TotalCardSales::Machine::TEF, 300.0) );
    cards.push_back( TotalCardSales(TotalCardSales::FlagAndMode::Diners,  TotalCardSales::Machine::TEF, 200.0) );
    cards.push_back( TotalCardSales(TotalCardSales::FlagAndMode::Maestro, TotalCardSales::Machine::TEF, 100.0) );

    notes = QString("Foi tudo bem nesse período. Nada de especial a comentar.");
}
