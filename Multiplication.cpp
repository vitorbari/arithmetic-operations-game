#include "Arduino.h"
#include "Multiplication.h"

const char *Multiplication::getSymbol()
{
    return "*";
}

OperatioValues Multiplication::draw()
{
    long multiplier = random(1, 3); // 1 to 2
    long multiplicand = random(10); // 0 to 10

    return OperatioValues{
        multiplier,
        multiplicand,
        multiplier * multiplicand,
    };
};