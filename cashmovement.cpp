#include "cashmovement.h"

CashMovement::CashMovement()
{

}

double CashMovement::value() const
{
    return amount * f;
}
