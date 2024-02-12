#include <Arduino.h>
#include <IRremote.h>
#include <NewPing.h>
#include "ultrasom.hpp"
#include "rodas.hpp"

// #include "infravermelhos.hpp";
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
const int trigPin1 = 8;
const int echoPin1 = 9;
const int trigPin2 = 10;
const int echoPin2 = 11;
const int trigPin3 = 12;
const int echoPin3 = 13;

// Objeto da classe Rodas
Rodas rodas(enaPin, in1Pin, in2Pin, enbPin, in3Pin, in4Pin);

// Objetos da classe Ultrasom
Ultrasom ultrassomDireita(trigPin1, echoPin1);
Ultrasom ultrassomMeio(trigPin2, echoPin2);
Ultrasom ultrassomEsquerda(trigPin3, echoPin3);

void setup() {
    // Inicializa os pinos dos sensores ultrassônicos
    ultrassomDireita.setup();
    ultrassomMeio.setup();
    ultrassomEsquerda.setup();

    // Inicializa os pinos dos motores
    rodas.setup();
}

void loop() {
    // Verifica se há obstáculos detectados pelos sensores
    bool obstaculoDireita = ultrassomDireita.detectarObjeto(20); // 20 cm de distância limite
    bool obstaculoMeio = ultrassomMeio.detectarObjeto(20);
    bool obstaculoEsquerda = ultrassomEsquerda.detectarObjeto(20);

    // Se houver obstáculo à direita, girar para a esquerda
    if (obstaculoDireita) {
        rodas.parar(); // Parar os motores
        rodas.girarEsquerda(1000); // Girar por 1 segundo
    }
    // Se houver obstáculo no meio, parar
    else if (obstaculoMeio) {
        rodas.parar(); // Parar os motores
    }
    // Se houver obstáculo à esquerda, girar para a direita
    else if (obstaculoEsquerda) {
        rodas.parar(); // Parar os motores
        rodas.girarDireita(1000); // Girar por 1 segundo
    }
    // Se não houver obstáculos, avançar
    else {
        rodas.frente(1000); // Avançar por 1 segundo
    }

    // Outras ações podem ser adicionadas aqui conforme necessário
}
