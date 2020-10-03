#include <Arduino.h>
#include <Servo.h>
#include <StepIt.h>

Servo myservo;

int pos;

void setup()
{
  // Serial begin
  Serial.begin(115200);
  delay(500);
  
  // Init da biblioteca de coordenadas
  stepit_init();
  
  // Servo config
  myservo.attach(9);
  myservo.write(1);
  delay(500);

  // Absolute positions
  pos = 0;
}

void loop()
{
  // eixo x = 37 mm total (FORWARD=DIR,BACKWARD=ESQ)
  // eixo y = 35 mm total (FORWARD=CIMA,BACJWARD=BAIXO)

  //axis_y.step(7 * 35, FORWARD, MICROSTEP); // = 1 mm * 35 = max
  //axis_y.release();

  step_to_it(" 8");

  delay(1000);

  step_to_it(" 1");

  delay(1000);

  step_to_it(" 9");

  delay(1000);

  step_to_it(" 3");

  delay(1000);

  step_to_it(" 7");

  delay(1000);

  step_to_it(" O");

  while (1);
  // axis_x.step(100, BACKWARD, MICROSTEP);
  // axis_y.step(100, FORWARD, MICROSTEP);
  // axis_y.step(100, BACKWARD, MICROSTEP);
  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(1);                       // waits 15ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(1);                       // waits 15ms for the servo to reach the position
  // }
}