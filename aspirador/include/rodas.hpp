#ifndef RODAS_H
#define RODAS_H

#include <Arduino.h>

class Rodas {
public:
    Rodas(int enaPin, int in1Pin, int in2Pin, int enbPin, int in3Pin, int in4Pin);
    void setup();
    void frente(int velocidade);
    void tras(int velocidade);
    void parar();
    void girarEsquerda(int velocidade);
    void girarDireita(int velocidade);

private:
    int enaPin;
    int in1Pin;
    int in2Pin;
    int enbPin;
    int in3Pin;
    int in4Pin;
};

#endif