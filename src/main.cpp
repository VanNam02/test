#include <Arduino.h> 
#include <LiquidCrystal_I2C.h>

int red = 12;
int yellow = 14;
int green = 27;

LiquidCrystal_I2C lcd(0x27,16,2);

byte pin[] = {15,2,4,5,18,19,13};   //   Seven segment pin is connected to Digital pin 15,2,4,5,18,19,21 to a,b,c,d,e,f,g

const byte count[10] = {  // this is data code for Seven segment 
0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F
  //GFEDCBA
  // B0111111,  //0
  // B0000110, // 1
  // B1011011, // 2
  // B1001111, //3
  // B1100110, //4
  // B1101101, //5
  // B1111101, //6
  // B0000111, //7
  // B1111111, //8
  // B01101111, //9
};

void setup() {
  Serial.begin(112500);
  pinMode(pin[0], OUTPUT);  // every pin is output
  pinMode(pin[1], OUTPUT);
  pinMode(pin[2], OUTPUT);
  pinMode(pin[3], OUTPUT);
  pinMode(pin[4], OUTPUT);
  pinMode(pin[5], OUTPUT);
  pinMode(pin[6], OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight(); 

}

void HienThi(int so) { //  sending data on each pin
  for(int i=0; i<8 ; i++)
  digitalWrite(pin[i],bitRead(count[so],i));
}

void loop() {
  //HienThi(1);
  digitalWrite(red,HIGH);
  lcd.clear();
   lcd.setCursor(0,0);
  lcd.print(" DUNG LAI"); 
  
 
  for(int i = 5; i>=0 ; i--){ // printing the number on seven segment
    HienThi(i);
    delay(1000);
    } 
      digitalWrite(red,LOW);
    digitalWrite(yellow,HIGH);
    lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("CHUAN BI"); 
   
    for (int i = 3; i >= 0; i--){
      HienThi(i);
      delay(1000);
    }
  
    digitalWrite(green,HIGH);
    digitalWrite(yellow,LOW); 
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("DI"); 
  
    for (int i = 9; i >= 0; i--){
      HienThi(i);
      delay(1000);
     
    }
    digitalWrite(red,HIGH);
    digitalWrite(yellow,LOW);
    digitalWrite(green,LOW);

  //   for(int j = 0; j<2; j++){ // printing the number on seven segment
  //   HienThi(j);
  //   delay(1000);
  //   digitalWrite(12,LOW);
  //   digitalWrite(14,HIGH);
  //   digitalWrite(27,LOW); 
  //   lcd.setCursor(0,0);
  // lcd.print(" CHUAN BI "); 
  //   } 
  //   for(int n = 0; n<5; n++){ // printing the number on seven segment
  //   HienThi(n);
  //   delay(1000);
  //   digitalWrite(12,LOW);
  //   digitalWrite(14,LOW);
  //   digitalWrite(27,HIGH); 
  //   lcd.setCursor(0,0);
  // lcd.print(" DUNG LAI "); 
  //   } 
  
} 