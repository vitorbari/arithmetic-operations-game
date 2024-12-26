// Display.h

#ifndef Display_h
#define Display_h

#include "Results.h"
#include "Operation.h"

#include <LiquidCrystal.h>

class Display
{
private:
    LiquidCrystal &lcd;

public:
    Display(LiquidCrystal &lcd);

    void results(Results results);

    void farewell();

    void question(OperatioValues values, const char *symbol);

    void result(OperatioValues values, const char *symbol);
};

#endif
