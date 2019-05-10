#ifndef RELFECHACAIXA_H
#define RELFECHACAIXA_H

#include <vector>
#include <QDateTime>

#include <cashpurse.h>
#include <cashmovement.h>
#include <totalcardsales.h>

class RelFechaCaixa
{
public:
    RelFechaCaixa();

    double totalCash() const;
    double totalCashMovement() const;
    double totalSales() const;
    double previousPeriodCash() const;
    double expectedCash() const;
    double cashDifference() const;

    void load();

    void addMovement(CashMovement const &movement);
    void addTotalCardSales(TotalCardSales const &cardSales);

private:
    int identifier; //id do período

    QDateTime period_init;
    QDateTime period_end;

    QString cashier; //responsável

    CashPurse cash; //dinheiro no caixa
    std::vector<CashMovement> movements; //depósitos e retiradas (reforços e sangrias) do caixa

    //período anterior
    double previous_period_cash; //total de dinheiro no período anterior
    double total_sales; //vendas em dinheiro neste período

    //total esperado no caixa = previous_period_sales + total_sales
    //diferença no caixa = previous_period_sales + total_sales - cash

    //vendas em cartões
    std::vector<TotalCardSales> cards;

    //conferências de papéis POS

    QString notes;
};

#endif // RELFECHACAIXA_H
