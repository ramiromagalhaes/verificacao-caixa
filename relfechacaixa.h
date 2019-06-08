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
    RelFechaCaixa(const int id, const double prevPeriodCash)
    {
        this->identifier = id;
        this->previous_period_cash = prevPeriodCash; //TODO implementar uma classe friend que carrega essa informação
    }

    int getId() const
    {
        return identifier;
    }

    void load();

    /**
     * @brief period_init data e hora do início do período
     */
    QDateTime period_init;

    /**
     * @brief period_end data e hora do dim do período
     */
    QDateTime period_end;

    /**
     * @brief cashier responsável pelo relatório
     */
    QString cashier;

    /**
     * @brief cash contagem de dinheiro no caixa
     */
    CashPurse cash;

    /**
     * @brief movements depósitos e retiradas do caixa feitas no período
     */
    std::vector<CashMovement> movements;

    /**
     * @brief total_sales vendas em dinheiro neste período
     */
    double total_sales;

    /**
     * @brief cards relatório de vendas em cartão
     */
    std::vector<TotalCardSales> cards;

    //TODO conferências de papéis POS

    /**
     * @brief notes observações sobre o relatório realizado nesse período
     */
    QString notes;

    double totalCashMovement() const
    {
        double total = .0;

        for(std::vector<CashMovement>::const_iterator it = movements.begin(); it != movements.end(); ++it) {
            total += it->value();
        }

        return total;
    }

    double previousPeriodCash() const
    {
        return previous_period_cash;
    }

    double expectedCash() const
    {
        return previous_period_cash + total_sales + totalCashMovement();
    }

    double cashDifference() const
    {
        return cash.getTotal() - expectedCash();
    }

private:

    /**
     * @brief identifier id do período no banco de dados
     */
    int identifier;

    /**
     * @brief previous_period_cash total de dinheiro no caixa do período anterior
     */
    double previous_period_cash;

};

#endif // RELFECHACAIXA_H
