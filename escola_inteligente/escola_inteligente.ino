


//bibliotecas
#include <DHT11.h>
#include <DHT.h>
#include <DHT_U.h>

 #define DHTPINO A2 //Definimos qual sera o pino para o sensor
 #define DHTTYPE DHT11 // variaveis do tipo DHT

 DHT dht(DHTPINO, DHT11 ); 


//variaveis globais sao da funcao acenderLEDAoDetectarPresenca
const int PIR = 2;  // Pino Digital que o PIR está plugado
const int ledAmarelo = 13;

//
const int MQ135 = A0;  // pino analogico do mq - 135
const int buzzer = 12;

void alarme_dois_tons() {
  int freqAlta = 2000;
  int freqBaixa = 800;
  int duracaoTom = 250;

  tone(buzzer, freqAlta, duracaoTom);
  delay(duracaoTom);
  tone(buzzer, freqBaixa, duracaoTom);
  delay(duracaoTom);
}

/*
void acenderLEDAoDetectarPresenca(){
  int estadoPIR = digitalRead(PIR); // le o pino Digital 2

 if (estadoPIR == HIGH){

 digitalWrite(ledAmarelo, HIGH);// fala ao programa que para pino 13 "acender"
 Serial.println("LED ligado");
 } else {
  digitalWrite(ledAmarelo, LOW);// fala ao programa que para pino 13 "acender"
  Serial.println("LED apagado");



  }

}
*/
void verificarVazamentoDeGas() {
  int estadoMQ135 = analogRead(MQ135);

  //if verificar a intensidade do valor do esatdoMQ135 >= 600
  //sim - ativar alarme
  //não - desativar alarme

  Serial.println(estadoMQ135);



  if (estadoMQ135 >= 400) {
    alarme_dois_tons();
  } else {
    noTone(buzzer);
  }
}



void vericarTemperaturaEUmidade(){
 float umidade = dht.readHumidity();
 float temperatura = dht.readTemperature();
 
Serial.println("umidade" + String (umidade) + "%");
Serial.println("temperatura: " + String (temperatura) + "c");

}

void setup() {
  Serial.begin(9600);
  pinMode(ledAmarelo, OUTPUT);

  pinMode(MQ135, INPUT);
  pinMode(buzzer, OUTPUT);
  
  //fala ao programa que o pino 13 sera uma saida/outout

  Serial.println("calibrando os sensores");
  delay(10000);
  Serial.println("sensores calibrando!!! ;) pode testar hehe");
}

void loop() {
  // As insruções no loop será somente chamada de funções
  // acenderLEDAoDetectarPresenca();
  //verificarVazamentoDeGas();
  //alarme_dois_tons();
  vericarTemperaturaEUmidade();
}
 