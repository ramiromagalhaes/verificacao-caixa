#include "totalcardsales.h"

TotalCardSales::TotalCardSales(const FlagAndMode fm, const Machine m, const double total)
{
    this->fm = fm;
    this->m = m;
    this->total = total;
}

TotalCardSales & TotalCardSales::operator=(TotalCardSales const & cardSales)
{
    this->fm = cardSales.fm;
    this->m = cardSales.m;
    this->total = cardSales.total;

    return *this;
}
