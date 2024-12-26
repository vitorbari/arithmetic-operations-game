#include "Arduino.h"
#include "Addition.h"

const char *Addition::getSymbol()
{
    return "+";
}

OperatioValues Addition::draw()
{
    long addend1 = random(11); // 0 to 10
    long addend2 = random(11); // 0 to 10

    return OperatioValues{
        addend1,
        addend2,
        addend1 + addend2,
    };
};