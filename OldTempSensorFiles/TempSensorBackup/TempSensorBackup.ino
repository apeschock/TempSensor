#include <LiquidCrystal.h>

byte nums[10][4][8] = {
{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11000,  B11001
  },{  B11100,  B11110,  B00011,  B00011,  B00111,  B01111,  B11111,  B11011
  },{  B11011,  B11111,  B11110,  B11100,  B11000,  B11000,  B01111,  B00111
  },{  B10011,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B00001,  B00011,  B00111,  B00111,  B00001,  B00001,  B00001,  B00001
  },{  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B10000
  },{  B00001,  B00001,  B00001,  B00001,  B00001,  B00001,  B00111,  B00111
  },{  B10000,  B10000,  B10000,  B10000,  B10000,  B10000,  B11100,  B11100
  }
},{
{  B00111,  B01111,  B11100,  B11000,  B00000,  B00000,  B00000,  B00000
  },{  B11100,  B11110,  B00111,  B00011,  B00011,  B00011,  B00110,  B01100
  },{  B00000,  B00001,  B00011,  B00110,  B01100,  B11000,  B11111,  B11111
  },{  B11000,  B10000,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111
  }
},{
{  B11111,  B11111,  B00000,  B00000,  B00000,  B00001,  B00001,  B00000
  },{  B11111,  B11111,  B01110,  B11100,  B11000,  B10000,  B11100,  B01110
  },{  B00000,  B00000,  B00000,  B00000,  B11000,  B11100,  B01111,  B00111
  },{  B00111,  B00011,  B00011,  B00011,  B00011,  B00111,  B11110,  B11100
  }
},{
{  B00000,  B00000,  B00001,  B00011,  B00110,  B01100,  B11000,  B11000
  },{  B01100,  B11100,  B11100,  B01100,  B01100,  B01100,  B01100,  B01100
  },{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000
  },{  B11111,  B11111,  B01100,  B01100,  B01100,  B01100,  B01100,  B01100
  }
},{
{  B11111,  B11111,  B11000,  B11000,  B11000,  B11000,  B11111,  B11111
  },{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B11100,  B11110
  },{  B00000,  B00000,  B00000,  B00000,  B11000,  B11100,  B01111,  B00111
  },{  B00011,  B00011,  B00011,  B00011,  B00011,  B00111,  B11110,  B11100
  }
},{
{  B00001,  B00011,  B00110,  B01100,  B11000,  B11000,  B11111,  B11111
  },{  B11100,  B11100,  B00000,  B00000,  B00000,  B00000,  B11100,  B11110
  },{  B11000,  B11000,  B11000,  B11000,  B11000,  B11000,  B01111,  B00111
  },{  B00011,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000,  B00001
  },{  B11111,  B11111,  B00011,  B00011,  B00111,  B01110,  B11100,  B11000
  },{  B00011,  B00111,  B01110,  B01100,  B01100,  B01100,  B01100,  B01100
  },{  B10000,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000,  B00000
  }
},{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11000,  B00111
  },{  B11100,  B11110,  B00011,  B00011,  B00011,  B00011,  B00011,  B11100
  },{  B00111,  B11000,  B11000,  B11000,  B11000,  B11000,  B01111,  B00111
  },{  B11100,  B00011,  B00011,  B00011,  B00011,  B00011,  B11110,  B11100
  }
},{
{  B00111,  B01111,  B11000,  B11000,  B11000,  B11000,  B11111,  B11111
  },{  B11100,  B11110,  B00011,  B00011,  B00011,  B00011,  B11111,  B11111
  },{  B00000,  B00000,  B00000,  B00000,  B00000,  B00000,  B00111,  B00111
  },{  B00011,  B00011,  B00011,  B00011,  B00110,  B01100,  B11000,  B10000
  }
}
};


const int button = 12;
const int lcdRs = 2;
const int lcdEn = 3;
const int lcd4 = 5;
const int lcd5 = 6;
const int lcd6 = 9;
const int lcd7 = 8;
LiquidCrystal lcd(lcdRs, lcdEn, lcd4, lcd5, lcd6, lcd7);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(button, INPUT_PULLUP);
  pinMode(lcdRs, OUTPUT);
  pinMode(lcdEn, OUTPUT);
  pinMode(lcd4, OUTPUT);
  pinMode(lcd5, OUTPUT);
  pinMode(lcd6, OUTPUT);
  pinMode(lcd7, OUTPUT);

  lcd.begin(8,2);
  lcd.clear();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.createChar(0, nums[0][0]);
  lcd.createChar(1, nums[0][1]);
  lcd.createChar(2, nums[0][2]);
  lcd.createChar(3, nums[0][3]);
  lcd.createChar(4, nums[1][0]);
  lcd.createChar(5, nums[1][1]);
  lcd.createChar(6, nums[1][2]);
  lcd.createChar(7, nums[1][3]);
  lcd.createChar(8, nums[2][0]);
  lcd.createChar(9, nums[2][1]);
  lcd.createChar(10, nums[2][2]);
  lcd.createChar(11, nums[2][3]);
  
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
  lcd.setCursor(4,0);
  lcd.write(byte(8));
  lcd.setCursor(5,0);
  lcd.write(byte(9));
  lcd.setCursor(4,1);
  lcd.write(byte(10));
  lcd.setCursor(5,1);
  lcd.write(byte(11));

  while(true){
    
  }
  
}
