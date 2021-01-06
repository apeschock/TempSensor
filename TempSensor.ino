#include <LiquidCrystal.h>
#include <LowPower.h>
#include "NumbersData.h"
#include "DebugUtils.h"

//flags for modes
/*this flag turns on the interior
temp display section*/
#define intTempDisp
//Debug mode is in the DebugUtils.h file
//to enable debug mode, uncomment line 1

//pin declarations
const int button = 2;
const int inSensor = A4;
const int outSensor = A2;
const int lcdRs = 3;
const int lcdEn = 4;
const int lcd4 = 5;
const int lcd5 = 6;
const int lcd6 = 9;
const int lcd7 = 8;
LiquidCrystal lcd(lcdRs, lcdEn, lcd4, lcd5, lcd6, lcd7);

void setup() {
  //start serial monitor if debug on
  DEBUG_BEGIN(9600);

  //set up pins
  pinMode(button, INPUT_PULLUP);
  pinMode(inSensor, INPUT);
  pinMode(outSensor, INPUT);
  pinMode(lcdRs, OUTPUT);
  pinMode(lcdEn, OUTPUT);
  pinMode(lcd4, OUTPUT);
  pinMode(lcd5, OUTPUT);
  pinMode(lcd6, OUTPUT);
  pinMode(lcd7, OUTPUT);

  //start the lcd
  lcd.begin(8,2);
  lcd.clear();
  lcd.noBlink();

  //set interrupt for button press
  attachInterrupt(digitalPinToInterrupt(button), changeUnit, FALLING);
}

boolean unitF = true;

void loop() {
  //read sensor and store temps
  float tempOut = analogRead(outSensor) * (5.0/1024.0);
  tempOut = ((tempOut - .5)*100.0);
  if(unitF){
    tempOut = (tempOut * 9.0/5.0) + 32.0;
  }

  //#if for the interior temp flag
  #if defined(intTempDisp)
    float inTemp = 0;
    inTemp = analogRead(inSensor) * (5.0/1024.0);
    inTemp = ((inTemp - .5)*100.0);
    if(unitF){
      inTemp = (inTemp * 9.0/5.0) + 32.0;
    }
    writeInTemp((int)inTemp);
  #endif
  
  //Get the different digits in an array
  int *outDigits = getValues((int)tempOut);

  //debug output TODO Figure the macro part out
  DEBUG_PRINTLN("Outside temp sensor: " + (String)tempOut);
  DEBUG_PRINT("Split Digits: ");
  DEBUG_PRINT(outDigits[0]);
  DEBUG_PRINT(outDigits[1]);
  DEBUG_PRINTLN(outDigits[2]);

  //write screen every iteration incase of temp change, will sleep for a while to cut power.
  writeScreen(outDigits);

  #ifndef DEBUG
    //Can sleep while waiting for an update if the screen doesn't need updated continuously.
    if(tempOut < 102){
      //low power mode for 8 seconds (max for the 328P)
      LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                  SPI_OFF, USART0_OFF, TWI_OFF);
    }
  #endif
}

//split number into separate digits
int * getValues(int orig){
  //allocate memory to store the split digits
  int* digits = new int [3];

  //if negative, first value is -1
  if(orig < 0){
    digits[0] = -1;
    orig *= -1;
  }else{
    digits[0] = 0;
  }
  for(int i=2; i>=0; --i){
    digits[i] = orig % 10;
    orig /= 10;
  }
  return digits;
}

void changeUnit(){
  //switch the unit flag when button pressed
  unitF = !unitF;
}

void writeScreen(int outDig[]){
  //setting up the custom chars
  //offset for a negative sign or another digit
  int prefixOffset = 0;

  //first digit in array will be a zero if not needed.
  if(outDig[0] == 1){
    //3 digits
    //display the first digit as a vertical line
    for(int i=0; i<=1; ++i){
      lcd.setCursor(0,i);
      lcd.write(0xFFFF);
    }
    ++prefixOffset;
  }else if(outDig[0] == -1){
    //display a negative sign and increase offset.
    lcd.setCursor(0,0);
    lcd.print("_");
    ++prefixOffset;
  }
  //2 digits
  //create the custom characters
  int charNum = 0;
  for(int i=1; i<3; ++i){
    for(int j=0; j<4; ++j){
      lcd.createChar(charNum, nums[outDig[i]][j]);
      ++charNum;
    }
  }

  //display the custom characters
  //charNum is for which byte needs chosen
  charNum = 0;
  //for 2 digits, increases by 2 to shift over a number space
  for(int i=0; i<3; i+=2){
    //j controls which row to place in
    for(int j=0; j<=1; ++j){
      //k is which column, which is added with i to offset a number, plus the prefix offset.
      for(int k=0; k<=1; ++k){
        lcd.setCursor(k+i+prefixOffset, j);
        //write the byte to the display and increment
        lcd.write(byte(charNum));
        ++charNum;
      }
    }
  }

  //clear the blank sections of the screen
  //in case switched from a 3 digit to 2 digit num
  if(prefixOffset == 0){
    for(int i=prefixOffset + 4; i<=5; ++i){
      for(int j=0; j<=1; ++j){
        lcd.setCursor(i, j);
        lcd.print(" ");
      }
    }
  }
  
  //clear the memory
  delete[] outDig;
  outDig = NULL;
  
  //add the units display
  lcd.setCursor(6,0);
  lcd.print((char)223);
  lcd.setCursor(7,0);
  if(unitF)
    lcd.write("F");
  else
    lcd.write("C");
}

#if defined(intTempDisp)
  void writeInTemp(int inTemp){
    DEBUG_PRINT("Interior temp: ");
    DEBUG_PRINTLN(inTemp);
    DEBUG_PRINTLN();
    //add the interior temp to screen
    int horiOffset = 6; //horizontal offset 6 moves to right side of screen
    int vertOffset = 1; //vertical offset 1 for lower row
    lcd.setCursor(horiOffset,vertOffset);
    if(inTemp < 100 && inTemp > -10){
      lcd.print(inTemp);
      return;
    }else if(inTemp >= 100){
      lcd.print("99");
      return;
    }else if(inTemp <= -10){
      lcd.print("-0");
    }
  }
#endif
