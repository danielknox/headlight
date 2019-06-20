#include <headlight.h>

//pin definition
#define IN1 8
#define IN2 7

//create a motor instance
Headlight headlight(IN1, IN2);

void setup() {

  //used for display information
  Serial.begin(9600);
}

void loop() {

  //tell the headlight to go mainbeam (may depend by your wiring)
  headlight.mainbeam();

  //print the headlight satus in the serial monitor
  Serial.print("Is on = ");
  Serial.println(headlight.isOn());

  delay(3000);

  //turn off headlight
  headlight.off();

  Serial.print("Is on = ");
  Serial.println(headlight.isOn());

  delay(3000);

  //tell the headlight to go dipped (may depend by your wiring)
  headlight.dipped();

  Serial.print("Is on = ");
  Serial.println(headlight.isOn());

  delay(3000);

  //turn off headlight
  headlight.off();

  Serial.print("Is on = ");
  Serial.println(headlight.isOn());

  delay(3000);
}
