#include <Arduino.h>
#include <StepIt.h>

String s;

void setup()
{
  // Serial begin
  Serial.begin(115200);
  delay(500);

  // Init da biblioteca de coordenadas
  stepit_init();
}

void loop()
{
  // eixo x = 37 mm total (FORWARD=DIR,BACKWARD=ESQ)
  // eixo y = 35 mm total (FORWARD=CIMA,BACJWARD=BAIXO)

  if (Serial.available())
  {
    //String s = Serial.readString();
    int c = Serial.read();
    if (c != -1)
    {
      s.concat((char)c);
      Serial.println(s);
      if (s.length() > 1)
      {
        if (step_to_it(s.c_str()))
        {
          //delay(300);
          click_it();
        }
        s = "";
      }
    }
  }

  //while (1);
}