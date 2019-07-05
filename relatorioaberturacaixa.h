#ifndef RELATORIOABERTURACAIXA_H
#define RELATORIOABERTURACAIXA_H

#include <QString>
#include <QDateTime>

class RelatorioAberturaCaixa
{
public:
    RelatorioAberturaCaixa();

    RelatorioAberturaCaixa(
            const int id,
            const int previous_period_id,
            const double previous_period_cash,
            const QDateTime timestamp = QDateTime::currentDateTime()) :
        identifier(id),
        previous_period_id(previous_period_id),
        previous_period_cash(previous_period_cash),
        timestamp(timestamp) {}

    /**
     * @brief identifier id do período no banco de dados
     */
    const int identifier;

    /**
     * @brief previous_period_id id do período anterior a este,
     * de onde algumas informações devem ser retiradas para conferência
     */
    const int previous_period_id;

    /**
     * @brief cashier responsável pelo relatório
     */
    const QString cashier;

    /**
     * @brief previous_period_cash total de dinheiro no caixa do período anterior
     */
    const double previous_period_cash;

    /**
     * @brief period_init data e hora do início do período
     */
    const QDateTime timestamp;

    /**
     * @brief cash contagem de dinheiro no caixa
     */
    CashPurse cash;

    /**
     * @brief notes observações sobre o relatório realizado nesse período
     */
    QString notes;

    /**
     * @brief expectedCash o total de dinheiro esperado no caixa no final do período deste relatório.
     * @return o dinheiro no final do período anterior mais o total de vendas deste período mais #totalCashMovement()
     */
    double expectedCash() const
    {
        return previous_period_cash;
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

#endif // RELATORIOABERTURACAIXA_H
