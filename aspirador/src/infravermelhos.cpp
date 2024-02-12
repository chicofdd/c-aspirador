#include "Arduino.h"
#include "infravermelhos.hpp"


Infravermelho::Infravermelho(int sensorPin) {
    this->sensorPin = sensorPin;
}

void Infravermelho::setup() {
    pinMode(sensorPin, INPUT);
}

float Infravermelho::medirDistancia() {
    // Ler a tensão analógica do sensor
    int valorSensor = analogRead(sensorPin);
    
    // Converter a leitura em uma distância (ajuste conforme necessário)
    // Aqui, estou supondo uma relação linear entre a tensão e a distância
    // Você precisará calibrar essa relação com base nas especificações do seu sensor
    float distancia = map(valorSensor, 0, 1023, 0, 100); // Mapear de 0 a 1023 para 0 a 100 cm
    
    return distancia;
}
