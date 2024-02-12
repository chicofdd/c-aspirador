#include <Arduino.h>
#include <IRremote.h>
#include <NewPing.h>
#include "ultrasom.hpp"
#include "rodas.hpp"
#include "infravermelhos.hpp"
// #include "carregamento.hpp"
// #include "aspiração.hpp"


// Definição dos pinos para os motores e ponte H L298N
const int enaPin = 0;  // Pino ENA
const int in1Pin = 4;   // Pino IN1
const int in2Pin = 5;   // Pino IN2
const int enbPin = 1;  // Pino ENB
const int in3Pin = 6;   // Pino IN3
const int in4Pin = 7;   // Pino IN4

// Definição dos pinos para os sensores ultrassônicos
const int trigPinDireita = 9;
const int echoPinDireita = 8;
const int trigPinMeio = 11;
const int echoPinMeio = 10;
const int trigPinEsquerda = 13;
const int echoPinEsquerda = 12;

const int infravermelhoPin = A0;

Rodas rodas(enaPin, in1Pin, in2Pin, enbPin, in3Pin, in4Pin);
Ultrasom ultrassomDireita(trigPinDireita, echoPinDireita);
Ultrasom ultrassomMeio(trigPinMeio, echoPinMeio);
Ultrasom ultrassomEsquerda(trigPinEsquerda, echoPinEsquerda);
Infravermelho infravermelho(infravermelhoPin);

void setup() {
    rodas.setup();
    ultrassomDireita.setup();
    ultrassomMeio.setup();
    ultrassomEsquerda.setup();
    infravermelho.setup();
}

void loop() {
    bool obstaculoDireita = ultrassomDireita.detectarObstaculoDireita(5); // 5 cm de distância limite
    bool obstaculoMeio = ultrassomMeio.detectarObstaculoMeio(5);
    bool obstaculoEsquerda = ultrassomEsquerda.detectarObstaculoEsquerda(5);
    
    float diferencaAltura = infravermelho.medirDistancia();

    if (obstaculoDireita || obstaculoMeio || obstaculoEsquerda || diferencaAltura > 10) {
        rodas.parar();
    } else {
        rodas.frente(1000);
    }

    delay(100); // Pequena pausa entre as verificações
}