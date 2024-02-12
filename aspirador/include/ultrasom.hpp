#ifndef ULTRASOM_H
#define ULTRASOM_H

#include <Arduino.h>

class Ultrasom {
public:
    Ultrasom(int trigPin, int echoPin);
    void setup();
    float medirDistancia();
    bool detectarObjeto(float distanciaLimite);

private:
    int trigPin;
    int echoPin;
};

#endif
