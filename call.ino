#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
 
#define pin 9

SoftwareSerial mySerial(10,11); 
LiquidCrystal lcd(2,3,4,5,6,7);
 
void setup()
{
 Serial.begin(9600); 
 mySerial.begin(9600);
 lcd.begin(16,2);
 lcd.print("   ACCIDENT    ");
 lcd.setCursor(0,1);
 lcd.print("DETECTION SYSTEM");
 delay(2000);
 lcd.clear();
 delay(2000);
}
 
void loop()
{
 lcd.clear();
 if (digitalRead(pin) == HIGH)
{
 lcd.print("ACCIDENT!!!");
 lcd.setCursor(0,1);
 lcd.print("CALING9429537567");
 delay(2000);
 mySerial.println("AT");
 mySerial.println("ATD+ +ZZxxxxxxxxxx;");
 delay(20000);
 mySerial.println("ATH");
}
else
{
 lcd.print("ACCIDENT!!!");
 lcd.setCursor(0,1);
 lcd.print("NOT DETECTION");
}
 delay(1000);
}
