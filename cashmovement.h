#ifndef CASHMOVEMENT_H
#define CASHMOVEMENT_H

#include <QString>
#include <QTime>

class CashMovement
{
public:
    enum Flow {
        inward = 1,
        outward = -1
    };

    CashMovement(QString description, QTime when, double amount, Flow f);

    double value() const;

    CashMovement & operator=(CashMovement const & movement);

    QString description;
    QTime when;
    double amount;
    Flow f;
};

#endif // CASHMOVEMENT_H
