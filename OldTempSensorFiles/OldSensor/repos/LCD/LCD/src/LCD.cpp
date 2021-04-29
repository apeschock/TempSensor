/*
 Name:		LCD.cpp
 Created:	5/3/2020 8:16:01 PM
 Author:	Austin
 Editor:	http://www.visualmicro.com
*/

#include "LCD.h"

//four bit mode setup
LCD::LCD(int rs, int en, int l4, int l5, int l6, int l7) {
	LiquidCrystal lcd(rs, en, l4, l5, l6, l7);
	//set up the screen with 8 col 2 row
	lcd.begin(8, 2);
	lcd.clear();
}

void LCD::print(string data) {
	lcd.print(data);
}

bool LCD::setUnit(string units) {
	if (units.toUpper() == "F") {
		unit = Fahrenheit;
	}
	else {
		unit = Celcius;
	}
}

int* getDigits(int temp) {
	//need to split into digits
	int* in = new int();
	*in = temp;
	int numDigits = 0;
	//divide by 10 and count til it becomes 0
	while (*in != 0) {
		++numDigits;
		*in /= 10;
	}
	delete in;

	int* digits = new int[numDigits];
	--numDigits;
	int* tempIn = new int();
	*tempIn = temp;
	while (numDigits >= 0) {
		*(digits + numDigits) = *tempIn % 10;
		*tempIn /= 10;
	}
	delete tempIn;
	return digits;
}

void LCD::DisplayTemp(int temp) {
	int* digits = getDigits(temp);

}