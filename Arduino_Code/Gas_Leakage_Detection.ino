#include <LiquidCrystal_I2C.h>
#include <Wire.h> //For I2C Communication

int GreenLedPin = 6;
int RedLedPin = 7;
int MQ2SensorPin = 5;   //Digital Pin

const int i2cAddress = 0x27; // Address of LCD module
const int lcdColumns = 16; //LCD columns 
const int lcdRows = 2; //LCD row

//LCD object with the I2C address, number of columns, and number of rows
LiquidCrystal_I2C lcd(i2cAddress, lcdColumns, lcdRows);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(GreenLedPin, OUTPUT);
  pinMode(RedLedPin, OUTPUT);
  pinMode(MQ2SensorPin, INPUT);
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = digitalRead(MQ2SensorPin);
  if (sensorValue == LOW)
  { 
    digitalWrite(RedLedPin, HIGH);
    digitalWrite(GreenLedPin, LOW);
    lcd.clear(); // Clear the LCD screen
    lcd.setCursor(0, 0); // Set cursor to the beginning of the first row
    lcd.print("Gas Detected!"); // Display message on LCD
    Serial.println("Gas Detected!"); // Print message on serial monitor
  }
  else
  {
    digitalWrite(GreenLedPin, HIGH);
    digitalWrite(RedLedPin, LOW);
    lcd.clear(); // Clear the LCD screen
    lcd.setCursor(0, 0); // Set cursor to the beginning of the first row
    lcd.print("No Gas Detected"); // Display message on LCD
    Serial.println("No Gas Detected"); // Print message on serial monitor
  }
  delay(1000);
}
