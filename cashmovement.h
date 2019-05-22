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

    CashMovement(QTime when, QString responsible, double amount, Flow f, QString description);

    double value() const;

    CashMovement & operator=(CashMovement const & movement);

    QTime when;
    QString responsible;
    QString description;
    double amount;
    Flow f;
};

#endif // CASHMOVEMENT_H
