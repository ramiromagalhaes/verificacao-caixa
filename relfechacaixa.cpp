#include "relfechacaixa.h"

#include <numeric>

RelFechaCaixa::RelFechaCaixa()
{

}

double RelFechaCaixa::totalCash()
{
    return cash.getTotal();
}

double RelFechaCaixa::totalCashMovement()
{
    double total = .0;

    for(std::vector<CashMovement>::iterator it = movements.begin(); it != movements.end(); ++it) {
        total += it->value();
    }

    return total;
}

double RelFechaCaixa::totalSales()
{
    return total_sales;
}

double RelFechaCaixa::previousPeriodCash()
{
    return previous_period_cash;
}

double RelFechaCaixa::expectedCash()
{
    return previous_period_cash + total_sales - totalCashMovement();
}

double RelFechaCaixa::cashDifference()
{
    return expectedCash() - totalCash();
}

#include <QDate>
#include <QTime>
void RelFechaCaixa::load() {
    identifier = 1;

    QDate date (2019, 5, 4);
    QTime time (10, 0);

    period_init = QDateTime(date, time);
    period_end = QDateTime();

    cashier = QString("João");

    //cash = CashPurse(); //TODO

    movements.clear();
    //movements.push_back();//TODO

    previous_period_cash = .0;
    total_sales = .0;

    cards.clear();

    notes = QString("Foi tudo bem nesse período. Nada de especial a comentar.");
}
