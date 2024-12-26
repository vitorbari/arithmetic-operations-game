// Operation.h

#ifndef Operation_h
#define Operation_h

struct OperatioValues
{
    long first;
    long second;
    long result;
};

class Operation
{
public:
    virtual OperatioValues draw() = 0;
    virtual const char *getSymbol() = 0;
};

#endif
