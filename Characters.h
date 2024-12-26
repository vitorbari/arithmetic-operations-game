// Characters.h

#ifndef Characters_h
#define Characters_h

/**
 * Custom LCD Characters
 *
 * Usage:
 * lcd.createChar(Characters::Smiley, Characters::SmileyB);
 * lcd.write(byte(Characters::Smiley));
 */

namespace Characters
{
    int Smiley = 0;

    int Frowning = 1;

    byte SmileyB[8] = {
        B00000,
        B10001,
        B00000,
        B00000,
        B10001,
        B01110,
        B00000,
    };

    byte FrowningB[8] = {
        B00000,
        B10001,
        B00000,
        B00000,
        B01110,
        B10001,
        B00000,
    };

}; // namespace Characters

#endif
