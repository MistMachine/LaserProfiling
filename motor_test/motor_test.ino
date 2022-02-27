#include <Stepper.h>
//initialize stepper functions
const int steps_per_revolution = 200;
Stepper my_stepper(steps_per_revolution, 6, 7, 8, 9);
int step_count = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  my_stepper.step(1);
  Serial.print("steps:");
  Serial.println(step_count);
  step_count++;
  delay(1000);
}
