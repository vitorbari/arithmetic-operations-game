// Local files
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include "Characters.h"
#include "Display.h"
#include "Results.h"

// Libs
#include <Keypad.h>
#include <LiquidCrystal.h>

// Keypad setup
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;

char keys[ROW_NUM][COLUMN_NUM] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}};

byte pinRows[ROW_NUM] = {5, 4, 3, 2};
byte pinColumn[COLUMN_NUM] = {9, 8, 7, 6};

Keypad keypad = Keypad(makeKeymap(keys), pinRows, pinColumn, ROW_NUM, COLUMN_NUM);

// LCD setup
const int rs = 12, en = 11, d4 = A2, d5 = A3, d6 = A4, d7 = A5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Display functions
Display display(lcd);

struct OperationMenu
{
	char key;
	String name;
	Operation &operation;
};

Addition operationAdd;
Subtraction operationSub;
Multiplication operationMul;
Division operationDiv;

#define OPERATIONS_SIZE 4
OperationMenu operations[OPERATIONS_SIZE] = {
	{'A', "Add", operationAdd},
	{'B', "Sub", operationSub},
	{'C', "Mul", operationMul},
	{'D', "Div", operationDiv}};

void setup()
{
	// initializes the pseudo-random number generator
	randomSeed(analogRead(A0));

	lcd.createChar(Characters::Smiley, Characters::SmileyB);
	lcd.createChar(Characters::Frowning, Characters::FrowningB);
	lcd.begin(16, 2);
}

void loop()
{
	// Display welcome message
	lcd.clear();
	lcd.print("Welcome! ");
	lcd.write(byte(Characters::Smiley));
	delay(3000);

	displayMenu();

	// Wait for use to enter menu option
	lcd.blink();
	OperationMenu operation = getOperation();

	lcd.noBlink();

	// Duration
	int duration = getDuration();

	Results results = gameStart(operation, duration);

	display.results(results);
	delay(5000);

	display.farewell();
	delay(3000);
}

Results gameStart(OperationMenu operationMenu, int duration)
{
	Results results;

	unsigned long start = millis();

	const char *symbol = operationMenu.operation.getSymbol();

	while ((millis() - start) / 1000 < duration)
	{
		OperatioValues values = operationMenu.operation.draw();

		int answer;

		do
		{
			display.question(values, symbol);
			answer = getNumber();
		} while (answer == -1); // restart if user presses *

		lcd.noBlink();

		if (values.result == answer)
		{
			results.right++;
			lcd.write(" ");
			lcd.write(byte(Characters::Smiley));
		}
		else
		{
			results.wrong++;
			lcd.write(" ");
			lcd.write(byte(Characters::Frowning));
		}

		display.result(values, symbol);
		delay(1500);
	}

	return results;
}

void displayMenu()
{
	lcd.clear();
	for (int i = 0; i < OPERATIONS_SIZE; i++)
	{
		lcd.print(operations[i].key);
		lcd.print("=");
		lcd.print(operations[i].name);

		// break line after second operation
		if (i == 1)
		{
			lcd.setCursor(0, 1);
			continue;
		}

		// Adds a space before the next item if it is not the last item
		if (i < OPERATIONS_SIZE - 1)
		{
			lcd.print(" ");
		}
	}
}

OperationMenu getOperation()
{
	do
	{
		char key = keypad.waitForKey();

		for (int i = 0; i < OPERATIONS_SIZE; i++)
		{
			if (key == operations[i].key)
			{
				return operations[i];
			}
		}
	} while (true);
}

int getDuration()
{
	int duration = 0;

	do
	{
		lcd.clear();
		lcd.setCursor(0, 1);
		lcd.print("(Minutes [1-20])");
		lcd.setCursor(0, 0);
		lcd.print("Duration: ");

		lcd.blink();
		duration = getNumber();
		lcd.noBlink();
	} while (duration <= 0 || duration > 20);

	// duration needs to be in seconds
	return duration * 60;
}

int getNumber()
{
	int num = 0;
	char key = keypad.getKey();

	while (key != '#')
	{
		switch (key)
		{
		case NO_KEY:
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			lcd.print(key);
			num = num * 10 + (key - '0');
			break;

		case '*':
			// return a signal that user wants to erase current answer
			return -1;
		}

		key = keypad.getKey();
	}

	return num;
}
