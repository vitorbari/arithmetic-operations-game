#include "Arduino.h"
#include "Display.h"
#include "Results.h"
#include "Operation.h"

#include <LiquidCrystal.h>

Display::Display(LiquidCrystal &l) : lcd(l)
{
}

void Display::results(Results results)
{
    lcd.clear();

    lcd.write(byte(0));
    lcd.print(" ");
    lcd.print(results.right);

    if (results.total() > 0)
    {
        lcd.print("  (");
        int percentage = results.right * 100.0 / results.total();
        lcd.print(percentage);
        lcd.print("%)");
    }

    lcd.setCursor(0, 1);

    lcd.write(byte(1));
    lcd.print(" ");
    lcd.print(results.wrong);
};

void Display::farewell()
{
    lcd.clear();
    lcd.print("Until next time.");
};

void Display::question(OperatioValues values, const char *symbol)
{
    lcd.clear();
    // TODO: format with printf
    lcd.print(values.first);
    lcd.print(symbol);
    lcd.print(values.second);
    lcd.print("=");
    lcd.blink();
};

void Display::result(OperatioValues values, const char *symbol)
{
    lcd.setCursor(0, 1);
    // TODO: format with printf
    lcd.print(values.first);
    lcd.print(symbol);
    lcd.print(values.second);
    lcd.print("=");
    lcd.print(values.result);
};