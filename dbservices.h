#ifndef DBSERVICES_H
#define DBSERVICES_H

#include <vector>
#include "relfechacaixa.h"

class DbServices
{
public:
    DbServices();

    std::vector<RelFechaCaixa> reports();

    void save(RelFechaCaixa report);

};

#endif // DBSERVICES_H
