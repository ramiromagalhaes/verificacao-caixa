#include "cashpurse.h"

CashPurse::CashPurse(QObject *parent) : QObject(parent)
{
    total = 0.0;
}

double CashPurse::getTotal() const
{
    return total;
}

void CashPurse::load()
{
    set50Bills(10);
    set20Bills(5);
    set10Bills(10);
}

void CashPurse::updateTotal()
{
    total = bills2 * 2.0 + bills5 * 5.0 + bills10 * 10.0 + bills20 * 20.0 + bills50 * 50.0 + bills100 * 100.0
            + cents1 * 0.01 + cents5 * 0.05 + cents10 * 0.1 + cents25 * 0.25 + cents50 * 0.5 + cents100;

    emit totalChanged(total);
}

void CashPurse::set2Bills   (int bills) { bills2   = bills; updateTotal(); }
void CashPurse::set5Bills   (int bills) { bills5   = bills; updateTotal(); }
void CashPurse::set10Bills  (int bills) { bills10  = bills; updateTotal(); }
void CashPurse::set20Bills  (int bills) { bills20  = bills; updateTotal(); }
void CashPurse::set50Bills  (int bills) { bills50  = bills; updateTotal(); }
void CashPurse::set100Bills (int bills) { bills100 = bills; updateTotal(); }

void CashPurse::set1Cents   (int cents) { cents1   = cents; updateTotal(); }
void CashPurse::set5Cents   (int cents) { cents5   = cents; updateTotal(); }
void CashPurse::set10Cents  (int cents) { cents10  = cents; updateTotal(); }
void CashPurse::set25Cents  (int cents) { cents25  = cents; updateTotal(); }
void CashPurse::set50Cents  (int cents) { cents50  = cents; updateTotal(); }
void CashPurse::set100Cents (int cents) { cents100 = cents; updateTotal(); }
