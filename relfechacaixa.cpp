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
