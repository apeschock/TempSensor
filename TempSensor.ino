#include <LiquidCrystal.h>
#include <LowPower.h>
#include "NumbersData.h"

//flag for interior temperature display
const bool intTempDisp = true;

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
  // put your setup code here, to run once:
  Serial.begin(9600);

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

  float inTemp;
  if(intTempDisp){
    inTemp = analogRead(inSensor) * (5.0/1024.0);
    inTemp = ((inTemp - .5)*100.0);
    if(unitF){
      inTemp = (inTemp * 9.0/5.0) + 32.0;
    }
  }
  
  //Get the different digits in an array
  int *outDigits = getValues((int)tempOut);

  //write screen every iteration incase of temp change, will sleep for a while to cut power.
  writeScreen(outDigits);
  if(intTempDisp){
    writeInTemp((int)inTemp);
  }
  
  //Can sleep while waiting for an update if the screen doesn't need updated continuously.
  if(tempOut < 102){
    //low power mode for 8 seconds (max for the 328P)
    LowPower.idle(SLEEP_8S, ADC_OFF, TIMER2_OFF, TIMER1_OFF, TIMER0_OFF, 
                SPI_OFF, USART0_OFF, TWI_OFF);
  }else{
    //if 3 numbers need displayed, have to update screen continuously, cannot sleep
  }
}

//split number into separate digits
//if negative, first value is -1
int * getValues(int orig){
  int digits [3];
  
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
  //switch the unit flag, then set the display to the new number and print it
  unitF = !unitF;
}

void writeScreen(int outDig[]){
  //setting up the custom chars
  //offset for a negative sign or another digit
  int prefixOffset = 0;
  //first digit in array will be a zero if not needed.
  if(outDig[0] == 1 || outDig[0] == -1){
    //TODO displaying 3 digits or negative sign
    
  }else{
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
        //k is which column, which is added with i to offset a number.
        for(int k=0; k<=1; ++k){
          lcd.setCursor(k+i, j);
          //write the byte to the display and increment
          lcd.write(byte(charNum));
          ++charNum;
        }
      }
    }
    
    //add the units display
    lcd.setCursor(5,0);
    lcd.print((char)223);
    lcd.setCursor(6,0);
    if(unitF)
      lcd.write("F");
    else
      lcd.write("C");
  }
}

void writeInTemp(int inTemp){
  //add the interior temp to screen
  int horiOffset = 6; //horizontal offset 6 moves to right side of screen
  int vertOffset = 1; //vertical offset 1 for lower row
  lcd.setCursor(horiOffset,vertOffset);
  if(inTemp < 100 && inTemp > -10){
    lcd.write(inTemp);
    return;
  }
  if(inTemp >= 100){
    lcd.write("99");
    return;
  }
  if(inTemp <= -10){
    lcd.write("-0");
  }
}
