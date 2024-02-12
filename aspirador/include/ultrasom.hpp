#ifndef ULTRASOM_H
#define ULTRASOM_H

#include <Arduino.h>

class Ultrasom {
public:
    Ultrasom(int trigPin, int echoPin);
    void setup();
    float medirDistancia();
    bool detectarObstaculoDireita(float distanciaLimite);
    bool detectarObstaculoEsquerda(float distanciaLimite);
    bool detectarObstaculoMeio(float distanciaLimite);

private:
    int trigPin;
    int echoPin;
};

#endif
