#ifndef RELFECHACAIXA_H
#define RELFECHACAIXA_H

#include <cashpurse.h>

class RelFechaCaixa
{
public:
    RelFechaCaixa();
private:
    //perídodo início e fim
    //responsável
    CashPurse cash;
    //depósitos e saques do caixa
    //total no caixa do período

    //período anterior
    //vendas em dinheiro no período anterior
    //vendas em dinheiro neste período
    //total esperado no caixa
    //diferença no caixa

    //vendas em cartões
    //conferências de papéis POS
};

#endif // RELFECHACAIXA_H
