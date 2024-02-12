#include "ultrasom.hpp"

Ultrasom::Ultrasom(int trigPin, int echoPin) {
    this->trigPin = trigPin;
    this->echoPin = echoPin;
}

void Ultrasom::setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

float Ultrasom::medirDistancia() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    
    float distance = duration * 0.034 / 2;
    
    return distance;
}

bool Ultrasom::detectarObstaculoDireita(float distanciaLimite) {
    float distancia = medirDistancia();
    return (distancia < distanciaLimite);
}

bool Ultrasom::detectarObstaculoEsquerda(float distanciaLimite) {
    // Medir a distância usando o sensor esquerdo
    float distancia = medirDistancia();
    return (distancia < distanciaLimite);
}

bool Ultrasom::detectarObstaculoMeio(float distanciaLimite) {
    // Medir a distância usando o sensor do meio
    float distancia = medirDistancia();
    return (distancia < distanciaLimite);
}
