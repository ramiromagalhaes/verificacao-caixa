#include "relfechacaixa.h"

RelFechaCaixa::RelFechaCaixa()
{

}

double RelFechaCaixa::totalCash() const
{
    return cash.getTotal();
}

double RelFechaCaixa::totalCashMovement() const
{
    double total = .0;

    for(std::vector<CashMovement>::const_iterator it = movements.begin(); it != movements.end(); ++it) {
        total += it->value();
    }

    return total;
}

double RelFechaCaixa::totalSales() const
{
    return total_sales;
}

double RelFechaCaixa::previousPeriodCash() const
{
    return previous_period_cash;
}

double RelFechaCaixa::expectedCash() const
{
    return previous_period_cash + total_sales - totalCashMovement();
}

double RelFechaCaixa::cashDifference() const
{
    return expectedCash() - totalCash();
}

void RelFechaCaixa::load()
{
    identifier = 1;

    period_init = QDateTime(QDate(2019, 5, 4), QTime(10, 0));
    period_end = QDateTime();

    cashier = QString("João");

    cash.load();

    movements.clear();
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,00), 100.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,10), 200.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Retirada"), QTime(11,30), 300.00, CashMovement::Flow::outward) );
    movements.push_back( CashMovement(QString("Depósito"), QTime(11,30), 600.10, CashMovement::Flow::inward) );

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

void RelFechaCaixa::addMovement(CashMovement const &movement) {
    movements.push_back( movement );
}

void RelFechaCaixa::addTotalCardSales(TotalCardSales const &cardSales){
    cards.push_back( cardSales );
}
