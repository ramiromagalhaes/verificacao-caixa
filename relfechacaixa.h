#ifndef RELFECHACAIXA_H
#define RELFECHACAIXA_H

#include <vector>
#include <QDateTime>

#include <QString>

#include <cashpurse.h>
#include <cashmovement.h>
#include <totalcardsales.h>

class RelFechaCaixa
{
public:
    RelFechaCaixa() {}

    RelFechaCaixa (QString cashier,
                   QDateTime periodInit = QDateTime::currentDateTime(),
                   double previousPeriodCash) :
        cashier(cashier),
        period_init(periodInit),
        previous_period_cash(previousPeriodCash) {};

    /**
     * @brief identifier id do período no banco de dados
     */
    int identifier;

    /**
     * @brief period_init data e hora do início do período
     */
    QDateTime period_init;

    /**
     * @brief period_end data e hora do dim do período
     */
    QDateTime period_end;

    /**
     * @brief previous_period_cash total de dinheiro no caixa do período anterior
     */
    double previous_period_cash = .0;

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
    double total_sales = .0;

    /**
     * @brief cards relatório de vendas em cartão
     */
    std::vector<TotalCardSales> cards;

    //TODO conferências de papéis POS

    /**
     * @brief notes observações sobre o relatório realizado nesse período
     */
    QString notes;

    /**
     * @brief indica se o relatório está concluído, portanto não deve ser alterado.
     */
    bool finished = false;

    /**
     * @brief totalCashMovement Soma todos os valores registrados em this.movements;
     * @return o somatório de dinheiro movimentado.
     */
    double totalCashMovement() const
    {
        double total = .0;

        for(std::vector<CashMovement>::const_iterator it = movements.begin(); it != movements.end(); ++it) {
            total += it->value();
        }

        return total;
    }

    /**
     * @brief expectedCash o total de dinheiro esperado no caixa no final do período deste relatório.
     * @return o dinheiro no final do período anterior mais o total de vendas deste período mais #totalCashMovement()
     */
    double expectedCash() const
    {
        return previous_period_cash + total_sales + totalCashMovement();
    }

    /**
     * @brief cashDifference a diferença entre o total de dinheiro no caixa e o valor esperado.
     * @return o total de dinheiro no caixa menos o total de dinheiro esperado no caixa.
     */
    double cashDifference() const
    {
        return cash.getTotal() - expectedCash();
    }

};

#endif // RELFECHACAIXA_H
