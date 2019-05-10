#include "cashmovement.h"

CashMovement::CashMovement(QString description, QTime when, double amount, Flow f)
{
    this->description = description;
    this->when = when;
    this->amount = amount;
    this->f = f;
}

double CashMovement::value() const
{
    return amount * f;
}

CashMovement & CashMovement::operator=(CashMovement const & movement)
{
    this->description = movement.description;
    this->when = movement.when;
    this->amount = movement.amount;
    this->f = movement.f;

    return *this;
}
