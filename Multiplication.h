// Multiplication.h

#include "Operation.h"

#ifndef Multiplication_h
#define Multiplication_h

class Multiplication : public Operation
{
public:
    OperatioValues draw();
    const char *getSymbol();
};

#endif
