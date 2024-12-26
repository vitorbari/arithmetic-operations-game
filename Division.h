// Division.h

#include "Operation.h"

#ifndef Division_h
#define Division_h

class Division : public Operation
{
public:
    OperatioValues draw();
    const char *getSymbol();
};

#endif
