#ifndef CASHMOVEMENT_H
#define CASHMOVEMENT_H

#include <QString>

class CashMovement
{
public:
    CashMovement();

    enum Flow {
        inward = 1,
        outward = -1
    };

    double value() const;

private:
    QString description;
    double amount;
    Flow f;
};

#endif // CASHMOVEMENT_H
