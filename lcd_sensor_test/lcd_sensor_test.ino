#include <LiquidCrystal.h>
// initialize lcd
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6,d7);

//initialize sensor
const int sensor_pin = A0;
int sensor_value = 0;

//piezo buzzer
const int piezo_pin = 10;
int piezo_value = 1;

//delay int variables
const int global_delay = 500;
void setup() {
  lcd.begin(16,2);
  lcd.print("Sensor:");
  Serial.begin(9600);
}

void loop() {
  delay(global_delay);
  
  sensor_value = analogRead(sensor_pin);
  // resets the cells containing the sensor readings
  lcd.setCursor(7,0);
  lcd.print("    ");
  
  //displays the sensor reading on the LCD display
  lcd.setCursor(7,0);
  lcd.print(sensor_value);
  
  //sends the data through serial communication
  Serial.print(sensor_value);
  Serial.print(',');
  piezo_value = sensor_value/20;
  tone(piezo_pin, piezo_value);
}
