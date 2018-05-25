#include "cashpurse.h"

CashPurse::CashPurse(QObject *parent) : QObject(parent)
{

}

void CashPurse::updateTotal()
{
    total = bills2 * 2 + bills5 * 5 + bills10 * 10 + bills20 * 20 + bills50 * 50 + bills100 * 100
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
