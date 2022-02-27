#include <LiquidCrystal.h>
#include <Stepper.h>
// initialize lcd
const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6,d7);

//initialize sensor
const int sensor_pin = A0;
int sensor_value = 0;

//piezo buzzer
const int piezo_pin = 11;
int piezo_value = 1;

//delay int variables
const int global_delay = 400;

//initialize stepper functions
const int steps_per_revolution = 200, num_iteration = 500;
Stepper my_stepper(steps_per_revolution, 6, 7, 8, 9);
int step_count = 0, step_size = 5, i = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Sensor:");
  lcd.setCursor(0,1);
  lcd.print("Step_count:");
  Serial.begin(9600);
}

void loop() {
  if (step_count == step_size*num_iteration)
  {step_size = -step_size;}
  if (step_count == -step_size)
  {step_size = -step_size;}

  // put your main code here, to run repeatedly:
  my_stepper.step(step_size);
  step_count= step_count+step_size;

  piezo_value = sensor_value/20;
  tone(piezo_pin, piezo_value);
  sensor_value = analogRead(sensor_pin);

  // resets the cells containing the sensor readings
  if (i % 20 == 0){
  lcd.setCursor(7,0);
  lcd.print("    ");
  lcd.setCursor(11,1);
  lcd.print("    ");

  // displays the sensor reading on the LCD display
  lcd.setCursor(7,0);
  lcd.print(sensor_value);
  lcd.setCursor(11,1);
  lcd.print(step_count);
  }
  // sends the data through serial communication
  Serial.print(sensor_value);
  Serial.print(',');
  Serial.print(step_count);
  Serial.print('\n');

  delay(global_delay);
  i = i +1;
}
