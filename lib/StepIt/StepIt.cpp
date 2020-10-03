#include "StepIt.h"

AF_Stepper axis_x(200, 2);
AF_Stepper axis_y(200, 1);

int posx, posy;

char mapa_valores[5][3][3] = {
    {"F1", "F2", " <"},
    {" 1", " 2", " 3"},
    {" 4", " 5", " 6"},
    {" 7", " 8", " 9"},
    {" X", " 0", " O"}};

int mapa_coords[5][3][2] = {
    {{0, 0}, {0, 129}, {0, 259}},
    {{61, 0}, {61, 129}, {61, 259}},
    {{122, 0}, {122, 129}, {122, 259}},
    {{183, 0}, {183, 129}, {183, 259}},
    {{244, 0}, {244, 129}, {244, 259}}};

void stepit_init()
{
    // Setting axis speed
    axis_x.setSpeed(100);
    axis_y.setSpeed(100);

    // Homming the axis
    home();

    posx = 0;
    posy = 0;
}

void step_x(int qtd, char dir)
{
    //axis_x.step(7 * 37, FORWARD, MICROSTEP); // = 1 mm * 37 = max
    axis_x.step(qtd, dir ? FORWARD : BACKWARD, MICROSTEP);
    posx += dir ? qtd : (qtd * -1);
    axis_x.release();
}

void step_y(int qtd, char dir)
{
    //axis_y.step(7 * 35, FORWARD, MICROSTEP); // = 1 mm * 35 = max
    axis_y.step(qtd, dir ? FORWARD : BACKWARD, MICROSTEP);
    posy += dir ? qtd : (qtd * -1);
    axis_y.release();
}

void home()
{
    step_x(7 * 37, 0);
    step_y(7 * 35, 0);
}

void step_to_it(const char *valor)
{
    int found_i = -1;
    int found_j = -1;
    //axis_y.step(7 * 35, FORWARD, MICROSTEP); // = 1 mm * 35 = max
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char *v = mapa_valores[i][j];
            if (strcmp(v, valor) == 0)
            {
                //Serial.print("Achei: ");
                //Serial.println(v);
                found_i = i;
                found_j = j;
                break;
            }
        }
        if (found_i != -1 && found_j != -1)
            break;
    }

    if (found_i != -1 && found_j != -1)
    {
        int posx_alvo = mapa_coords[found_i][found_j][1];
        int posy_alvo = mapa_coords[found_i][found_j][0];

        // Serial.print("X coord alvo: ");
        // Serial.println(posx_alvo);
        // Serial.print("Y coord alvo: ");
        // Serial.println(posy_alvo);

        // Serial.print("X coord origem: ");
        // Serial.println(posx);
        // Serial.print("Y coord origem: ");
        // Serial.println(posy);

        step_x(abs(posx_alvo - posx), posx > posx_alvo ? 0 : 1);
        step_y(abs(posy_alvo - posy), posy > posy_alvo ? 0 : 1);
    }

    //axis_y.step(qtd, dir ? FORWARD : BACKWARD, MICROSTEP);
    //axis_y.release();
}