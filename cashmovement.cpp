#include "cashmovement.h"

CashMovement::CashMovement(QTime when, QString responsible, double amount, Flow f, QString description)
{
    this->when = when;
    this->responsible = responsible;
    this->amount = amount;
    this->f = f;
    this->description = description;
}

double CashMovement::value() const
{
    return amount * f;
}

CashMovement & CashMovement::operator=(CashMovement const & movement)
{
    this->when = movement.when;
    this->responsible = movement.responsible;
    this->amount = movement.amount;
    this->f = movement.f;
    this->description = movement.description;

    return *this;
}
