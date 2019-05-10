#ifndef CASHPURSE_H
#define CASHPURSE_H

#include <QObject>

class CashPurse : public QObject
{
    Q_OBJECT
public:
    explicit CashPurse(QObject *parent = 0);

    double getTotal() const;

    void load();

signals:
    void totalChanged(double total);

public slots:
    void set2Bills   (int bills);
    void set5Bills   (int bills);
    void set10Bills  (int bills);
    void set20Bills  (int bills);
    void set50Bills  (int bills);
    void set100Bills (int bills);

    void set1Cents   (int cents);
    void set5Cents   (int cents);
    void set10Cents  (int cents);
    void set25Cents  (int cents);
    void set50Cents  (int cents);
    void set100Cents (int cents);

private:
    void updateTotal();

    int bills2 = 0, bills5 = 0, bills10 = 0, bills20 = 0, bills50 = 0, bills100 = 0,
        cents1 = 0, cents5 = 0, cents10 = 0, cents25 = 0, cents50 = 0, cents100 = 0;

    double total;

};

#endif // CASHPURSE_H
