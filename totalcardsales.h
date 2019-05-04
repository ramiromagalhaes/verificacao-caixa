#ifndef TOTALCARDSALES_H
#define TOTALCARDSALES_H


class TotalCardSales
{
public:
    TotalCardSales();

    enum FlagAndMode {
        Mastercard = 0,
        Maestro = 1,
        Visa = 2,
        Visa_Electron = 3,
        Amex = 4,
        Elo = 5,
        Diners = 6,
        Visa2x = 7,
        Visa3x = 8,
        Mastercard2x = 9,
        Mastercard3x = 10,
        Amex2x = 11,
        Amex3x = 12
    };

    enum Machine {
        POS = 0,
        TEF = 1
    };

private:
    FlagAndMode fm;
    Machine m;
    double total;

};

#endif // TOTALCARDSALES_H
