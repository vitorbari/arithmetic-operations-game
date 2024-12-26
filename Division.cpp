#include "Arduino.h"
#include "Division.h"

const char *Division::getSymbol()
{
    return "/";
}

OperatioValues Division::draw()
{
    long dividend;
    long divisor;

    do
    {
        dividend = random(0, 21); // 0 to 20
        divisor = random(2, 10);  // 2 to 3
    } while (dividend % divisor != 0);

    return OperatioValues{
        dividend,
        divisor,
        dividend / divisor,
    };
};