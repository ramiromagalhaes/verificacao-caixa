#ifndef DBSERVICES_H
#define DBSERVICES_H

#include <vector>
#include "relfechacaixa.h"

class DbServices
{
private:
    DbServices() {}

public:
    static std::vector<RelFechaCaixa> * reports();

    static void save(const RelFechaCaixa & report);

    static void finish(const RelFechaCaixa & report);
};

#endif // DBSERVICES_H
