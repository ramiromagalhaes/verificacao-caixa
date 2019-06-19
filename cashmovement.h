#ifndef CASHMOVEMENT_H
#define CASHMOVEMENT_H

#include <QString>
#include <QTime>

class CashMovement
{
public:
    enum Flow : int
    {
        inward = 1,
        outward = -1
    };

    CashMovement(QTime when = QTime::currentTime(),
                 QString responsible = "",
                 double amount = .0,
                 Flow f = Flow::inward,
                 QString description = "")
        : when(when), responsible(responsible), amount(amount), f(f), description(description) {}

    double value() const
    {
        return amount * f;
    }

    QTime when;
    QString responsible;
    double amount;
    Flow f;
    QString description;
};

#endif // CASHMOVEMENT_H
