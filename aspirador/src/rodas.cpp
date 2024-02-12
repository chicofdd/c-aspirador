#include "rodas.hpp"

Rodas::Rodas(int enaPin, int in1Pin, int in2Pin, int enbPin, int in3Pin, int in4Pin) {
    this->enaPin = enaPin;
    this->in1Pin = in1Pin;
    this->in2Pin = in2Pin;
    this->enbPin = enbPin;
    this->in3Pin = in3Pin;
    this->in4Pin = in4Pin;
}

void Rodas::setup() {
    pinMode(enaPin, OUTPUT);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(enbPin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);
}

void Rodas::frente(int velocidade) {
    digitalWrite(enaPin, HIGH);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    digitalWrite(enbPin, HIGH);
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, LOW);
    delay(velocidade);
}

void Rodas::tras(int velocidade) {
    digitalWrite(enaPin, HIGH);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    digitalWrite(enbPin, HIGH);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, HIGH);
    delay(velocidade);
}

void Rodas::parar() {
    digitalWrite(enaPin, LOW);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);
    digitalWrite(enbPin, LOW);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, LOW);
}

void Rodas::girarEsquerda(int velocidade) {
    digitalWrite(enaPin, HIGH);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    digitalWrite(enbPin, HIGH);
    digitalWrite(in3Pin, HIGH);
    digitalWrite(in4Pin, LOW);
    delay(velocidade);
}

void Rodas::girarDireita(int velocidade) {
    digitalWrite(enaPin, HIGH);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);
    digitalWrite(enbPin, HIGH);
    digitalWrite(in3Pin, LOW);
    digitalWrite(in4Pin, HIGH);
    delay(velocidade);
}
