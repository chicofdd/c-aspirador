#ifndef INFRARED_H
#define INFRARED_H

#include <Arduino.h>

class Infravermelho {
public:
    Infravermelho(int sensorPin);
    void setup();
    float medirDistancia();

private:
    int sensorPin;
};

#endif
