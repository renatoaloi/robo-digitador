#include <Arduino.h>
#include <AFMotor.h>
#include <Servo.h>

void stepit_init();
void step_x(int qtd, char dir);
void step_y(int qtd, char dir);
void home();
bool step_to_it(const char *valor);
void click_it();
