#include <LiquidCrystal_I2C.h>

const int potPin = A0;   
const int relayPin = 2;  
const int thresholdValueOfMoisture = 512; 

LiquidCrystal_I2C lcd(0x38, 20, 4);

void setup() {
  lcd.begin(20, 4);
  lcd.backlight();
  lcd.clear();

  lcd.print("Snail Repellant");
  delay(2000);

  lcd.clear(); 
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); 

  }

void loop() {
  int val = analogRead(potPin); 

  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(val);
  lcd.print("   ");  // Clear residual characters

  lcd.setCursor(0, 1);
  
  if (val >= thresholdValueOfMoisture) {
    digitalWrite(relayPin, HIGH);
    lcd.print("SNAIL DETECTED!  ");
    delay(1000);
    lcd.setCursor(0, 1);  // Some displays need this refresh
    lcd.print("Buzzer: ON     "); 
    delay(1000);
  } 
  else {
    digitalWrite(relayPin, LOW);
    lcd.print("No snail found  ");
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("Buzzer: OFF   ");
    delay(1000);  
  }
  
  }

