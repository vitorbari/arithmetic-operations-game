#include "Arduino.h"
#include "Subtraction.h"

const char *Subtraction::getSymbol()
{
    return "-";
}

OperatioValues Subtraction::draw()
{
    long minuend = random(1, 11);          // 1 to 10
    long subtrahend = random(minuend + 1); // 0 to minuend

    return OperatioValues{
        minuend,
        subtrahend,
        minuend - subtrahend,
    };
};