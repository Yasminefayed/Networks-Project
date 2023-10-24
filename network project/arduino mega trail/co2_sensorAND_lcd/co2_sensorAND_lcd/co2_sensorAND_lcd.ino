#include <LiquidCrystal_I2C.h>

#include <Wire.h> 

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int sensorValue;
//int digitalValue;
const int buzzer = 2;///pin D2 buzzer
void setup()
{
  Serial.begin(9600); // sets the serial port to 9600
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(0); // read analog input pin 0
   if (sensorValue > 100)////change as we want 7asab co2 level
  {
    Serial.println("above 100");
    lcd.setCursor(2,0);///first line in lcd
    lcd.print("above 100");
    lcd.setCursor(2,1);///second line in lcd
    lcd.print("CO2 LEVEL=");lcd.print(sensorValue,DEC);
    digitalWrite(buzzer, HIGH);
  }
  else
   
  digitalWrite(buzzer, LOW);
  Serial.println(sensorValue, DEC); // prints the value read
  lcd.setCursor(2,0);///first line in lcd
  lcd.print("below 100");
  lcd.setCursor(2,1);///second line in lcd
  lcd.print("CO2 LEVEL=");
  lcd.print(sensorValue,DEC);
   delay(1000); // wait 100ms for next reading
}
