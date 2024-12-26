// Subtraction.h

#include "Operation.h"

#ifndef Subtraction_h
#define Subtraction_h

class Subtraction : public Operation
{
public:
    OperatioValues draw();
    const char *getSymbol();
};

#endif
