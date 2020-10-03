#include <Arduino.h>
#include <AFMotor.h>

void stepit_init();
void step_x(int qtd, char dir);
void step_y(int qtd, char dir);
void home();
void step_to_it(const char *valor);
