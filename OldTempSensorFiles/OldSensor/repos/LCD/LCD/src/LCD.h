/*
lcdnum.h - Handles the creation and displayiing of
custom characters in arduino to use two rows of an lcd
for better readability
- Austin Peschock 4/29/2020
*/

#ifndef _LCD_h
#define _LCD_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
    #include <LiquidCrystal.h>
class LCD {
public:
	LCD(int reset, int enable, int data4, int data5, int data6, int data7);
	void print(string strToPrint);
	bool setUnit(string FOrC);
	void DisplayTemp(int Temperature);

}

#endif
#endif