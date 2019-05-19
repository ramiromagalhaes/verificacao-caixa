#ifndef TOTALCARDSALES_H
#define TOTALCARDSALES_H


class TotalCardSales
{
public:
    enum FlagAndMode {
        Mastercard = 1,
        Maestro = 2,
        Visa = 3,
        Visa_Electron = 4,
        Amex = 5,
        Elo = 6,
        Diners = 7,
        Visa2x = 8,
        Visa3x = 9,
        Mastercard2x = 10,
        Mastercard3x = 11,
        Amex2x = 12,
        Amex3x = 13
    };

    enum Machine {
        POS = 0,
        TEF = 1
    };

    TotalCardSales(const FlagAndMode fm, const Machine m, const double total);

    TotalCardSales & operator=(TotalCardSales const & cardSales);

    FlagAndMode fm;
    Machine m;
    double total;

};

#endif // TOTALCARDSALES_H
