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
const int sensor = A4;
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
  pinMode(sensor, INPUT);
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
boolean unitF = true;
int digits[3];

void loop() {
  //read sensor and store temps
  tempC = analogRead(sensor) * (5.0/1024.0);
  tempC = ((tempC - .5)*100.0);
  tempF = (tempC * 9.0/5.0) + 32.0;

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
  getValues((int)tempDisp);
  
  //write screen every iteration incase of temp change, will sleep for a while to cut power.
  writeScreen(digits);

  //Can sleep while waiting for an update if the screen doesn't need updated continuously.
  //Make this a real sleep for the cpu
  if(tempDisp < 102){
    delay(1000);
  }else{
    //keep displaying to put up 3 numbers
  }
}

//split number into digits and store that in global digits array
//if negative, first value is -1, then invert to find digits
void getValues(int orig){
  if(orig < 0){
    digits[0] = -1;
    orig *= -1;
  }
  for(int i=2; i>=0; ++i){
    digits[i] = orig % 10;
    orig /= 10;
  }
}

void changeUnit(){
  //switch the unit flag, then set the display to the new number and print it
  unitF = !unitF;
}

void writeScreen(int dig[]){
  //set the custom chars
  //first digit will be a zero if not needed.
  if(dig[0] == 1 || dig[0] == -1){
    //displaying 3 digits or negative sign
    
  }else{
    //2 digits
    //create the custom characters
    int charNum = 0;
    for(int i=1; i<3; ++i){
      for(int j=0; j<4; ++j){
        lcd.createChar(charNum, nums[dig[i]][j]);
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
    //add the units
    lcd.setCursor(5,0);
    lcd.print((char)223);
    lcd.setCursor(6,0);
    if(unitF)
      lcd.write("F");
    else
      lcd.write("C");
  }
}

void writeScreen(int temp){
  //basic, needs updated to handle 3 numbers, use loops
  //also need to create the custom characters here


  int k=0;
  for(int i=0; i<=3; ++i){
    for(int j=0; j<=1; ++j){
      lcd.setCursor(i, j);
      lcd.write(byte(k));
      ++k;
    }
  }
  
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.setCursor(1,0);
  lcd.write(byte(1));
  lcd.setCursor(0,1);
  lcd.write(byte(2));
  lcd.setCursor(1,1);
  lcd.write(byte(3));
  lcd.setCursor(2,0);
  lcd.write(byte(4));
  lcd.setCursor(3,0);
  lcd.write(byte(5));
  lcd.setCursor(2,1);
  lcd.write(byte(6));
  lcd.setCursor(3,1);
  lcd.write(byte(7));

  lcd.setCursor(5,0);
  lcd.print((char)223);
  lcd.setCursor(6,0);
  if(unitF)
    lcd.write("F");
  else
    lcd.write("C");
}
