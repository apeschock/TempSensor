#include <LiquidCrystal.h>

//all the byte data to display the numbers
byte nums[10][4][8] = {
{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11000,  B11001
  },{  B11011,  B11111,  B11110,  B11100,  B11000,  B11000,  B01111,  B00111
  },{  B11100,  B11110,  B00011,  B00011,  B00111,  B01111,  B11111,  B11011
  },{  B10011,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B00001,  B00011,  B00111,  B00111,  B00001,  B00001,  B00001,  B00001
  },{  B00001,  B00001,  B00001,  B00001,  B00001,  B00001,  B00111,  B00111
  },{  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000
  },{  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B11100,  B11100
  }
},{
{  B00111,  B01111,  B11100,  B11000,  B00000,  B00000,  B00000,  B00000
  },{  B00000,  B00001,  B00011,  B00110,  B01100,  B11000,  B11111,  B11111
  },{  B11100,  B11110,  B00111,  B00011,  B00011,  B00011,  B00110,  B01100
  },{  B11000,  B10000,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111
  }
},{
{  B11111,  B11111,  B00000,  B00000,  B00000,  B00001,  B00001,  B00000
  },{  B00000,  B00000,  B00000,  B00000,  B11000,  B11100,  B01111,  B00111
  },{  B11111,  B11111,  B01110,  B11100,  B11000,  B10000,  B11100,  B01110
  },{  B00111,  B00011,  B00011,  B00011,  B00011,  B00111,  B11110,  B11100
  }
},{
{  B00000,  B00000,  B00001,  B00011,  B00110,  B01100,  B11000,  B11000
  },{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000
  },{  B01100,  B11100,  B11100,  B01100,  B01100,  B01100,  B01100,  B01100
  },{  B11111,  B11111,  B01100,  B01100,  B01100,  B01100,  B01100,  B01100
  }
},{
{  B11111,  B11111,  B11000,  B11000,  B11000,  B11000,  B11111,  B11111
  },{  B00000,  B00000,  B00000,  B00000,  B11000,  B11100,  B01111,  B00111
  },{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B11100,  B11110
  },{  B00011,  B00011,  B00011,  B00011,  B00011,  B00111,  B11110,  B11100
  }
},{
{  B00001,  B00011,  B00110,  B01100,  B11000,  B11000,  B11000,  B11111
  },{  B11111,  B11000,  B11000,  B11000,  B11000,  B11000,  B01111,  B00111
  },{  B11100,  B11100,  B00000,  B00000,  B00000,  B00000,  B00000,  B11110
  },{  B11111,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000,  B00001
  },{  B00011,  B00111,  B01110,  B01100,  B01100,  B01100,  B01100,  B01100
  },{  B11111,  B11111,  B00011,  B00011,  B00111,  B01110,  B11100,  B11000
  },{  B10000,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000
  }
},{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11000,  B00111
  },{  B00111,  B11000,  B11000,  B11000,  B11000,  B11000,  B01111,  B00111
  },{  B11100,  B11110,  B00011,  B00011,  B00011,  B00011,  B00011,  B11100
  },{  B11100,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11000,  B11111
  },{  B01111,  B00000,  B00000,  B00000,  B00000,  B00000,  B00111,  B00111
  },{  B11100,  B11110,  B00011,  B00011,  B00011,  B00011,  B00011,  B11111
  },{  B11111,  B00011,  B00011,  B00011,  B00110,  B01100,  B11000,  B10000
  }
}
};

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

float tempC;
float tempF;
float tempDisp = 0;
float inTemp;
boolean unitF = true;

void loop() {
  //read sensor and store temps
  //TODO: celcius on inside sensor
  tempC = analogRead(outSensor) * (5.0/1024.0);
  tempC = ((tempC - .5)*100.0);
  tempF = (tempC * 9.0/5.0) + 32.0;
  inTemp = analogRead(inSensor) * (5.0/1024.0);
  inTemp = ((inTemp - .5)*100.0);
  inTemp = (inTemp * 9.0/5.0) + 32.0;

  if(unitF){
    if(tempDisp != tempF){
      tempDisp = tempF;
      //write to screen later
    }
  }else{
    if(tempDisp != tempC){
      tempDisp = tempC;
      //write to screen later
    }
  }
  
  //Get the different digits in an array
  int *outDigits = getValues((int)tempDisp);
  int *inDigits = getValues((int)inTemp);
  
  //write screen every iteration incase of temp change, will sleep for a while to cut power.
  writeScreen(outDigits, inDigits);

  //Can sleep while waiting for an update if the screen doesn't need updated continuously.
  //Make this a real sleep for the cpu
  if(tempDisp < 102){
    delay(1000);
  }else{
    //keep displaying to put up 3 numbers
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

void writeScreen(int outDig[], int inDig[]){
  //set the custom chars
  //first digit will be a zero if not needed.
  if(outDig[0] == 1 || outDig[0] == -1){
    //displaying 3 digits or negative sign
    
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
    //add the interior temp
    for(int i=0; i<2; ++i){
      lcd.setCursor(i+6,1); //+6 offset for right side
      lcd.write(inDig[i]);
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
