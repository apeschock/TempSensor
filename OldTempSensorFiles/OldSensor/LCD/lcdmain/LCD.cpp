#include "Arduino.h"
#include "LCD.h"

//four bit mode setup
LCD::LCD(int rs, int en, int l4, int l5, int l6, int l7) {
  LiquidCrystal lcd = LiquidCrystal(rs, en, l4, l5, l6, l7);
  //set up the screen with 8 col 2 row
  lcd.begin(8, 2);
  lcd.clear();
}

void LCD::print(String data) {
  lcd.print(data);
}

bool LCD::setUnit(String units) {
  units.toUpperCase();
  if (units == "F") {
    unit = Fahrenheit;
    return true;
  }
  else {
    unit = Celcius;
    return true;
  }
  return false;
}

int* getDigits(int temp) {
  //need to split into digits
  int in = temp;
  int numDigits = 0;
  //divide by 10 and count til it becomes 0
  while (in != 0) {
    ++numDigits;
    in /= 10;
  }

  int* digits = new int[numDigits];
  --numDigits;
  while (numDigits >= 0) {
    *(digits + numDigits) = temp % 10;
    temp /= 10;
  }
  return digits;
}

void LCD::DisplayTemp(int temp) {
  int* digits = getDigits(temp);

}
