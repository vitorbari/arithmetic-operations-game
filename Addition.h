// Addition.h

#include "Operation.h"

#ifndef Addition_h
#define Addition_h

class Addition : public Operation
{
public:
    OperatioValues draw();
    const char *getSymbol();
};

#endif
