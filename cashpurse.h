#ifndef CASHPURSE_H
#define CASHPURSE_H


class CashPurse
{
public:
    CashPurse() {}

    double getTotal()      const { return total;      }
    double getTotalBills() const { return totalBills; }
    double getTotalCoins() const { return totalCoins; }

    int get2Bills   () const { return bills2;   }
    int get5Bills   () const { return bills5;   }
    int get10Bills  () const { return bills10;  }
    int get20Bills  () const { return bills20;  }
    int get50Bills  () const { return bills50;  }
    int get100Bills () const { return bills100; }

    int get1Cents   () const { return cents1;   }
    int get5Cents   () const { return cents5;   }
    int get10Cents  () const { return cents10;  }
    int get25Cents  () const { return cents25;  }
    int get50Cents  () const { return cents50;  }
    int get100Cents () const { return cents100; }

    void set2Bills   (int bills) { bills2   = bills; updateTotals(); }
    void set5Bills   (int bills) { bills5   = bills; updateTotals(); }
    void set10Bills  (int bills) { bills10  = bills; updateTotals(); }
    void set20Bills  (int bills) { bills20  = bills; updateTotals(); }
    void set50Bills  (int bills) { bills50  = bills; updateTotals(); }
    void set100Bills (int bills) { bills100 = bills; updateTotals(); }

    void set1Cents   (int cents) { cents1   = cents; updateTotals(); }
    void set5Cents   (int cents) { cents5   = cents; updateTotals(); }
    void set10Cents  (int cents) { cents10  = cents; updateTotals(); }
    void set25Cents  (int cents) { cents25  = cents; updateTotals(); }
    void set50Cents  (int cents) { cents50  = cents; updateTotals(); }
    void set100Cents (int cents) { cents100 = cents; updateTotals(); }

private:
    void updateTotals()
    {
        totalBills = bills2 * 2.0 + bills5 * 5.0 + bills10 * 10.0 + bills20 * 20.0 + bills50 * 50.0 + bills100 * 100.0;
        totalCoins = cents1 * 0.01 + cents5 * 0.05 + cents10 * 0.1 + cents25 * 0.25 + cents50 * 0.5 + cents100 * 1.0;
        total = totalBills + totalCoins;
    }

    double total = .0;
    double totalBills = .0;
    double totalCoins = .0;

    int bills2 = 0, bills5 = 0, bills10 = 0, bills20 = 0, bills50 = 0, bills100 = 0,
        cents1 = 0, cents5 = 0, cents10 = 0, cents25 = 0, cents50 = 0, cents100 = 0;

};

#endif // CASHPURSE_H
