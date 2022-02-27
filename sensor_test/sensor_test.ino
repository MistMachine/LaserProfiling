
const int sensor_pin = 0;
int sensor_value = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.print("Int:");
  sensor_value = analogRead(sensor_pin);
  Serial.print(sensor_value);
}
