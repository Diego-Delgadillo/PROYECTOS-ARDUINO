/*
Hecho por DRDG_1 
Fecha: 27/12/2022
*/

int ledPin = 13;    // pin del led
int sensorPin = 2;  // pin del sensor

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); // Declaramos el pin del LED como una salida
  pinMode(sensorPin, INPUT); // Decalramos el pin del sensor como una entrada
  digitalWrite(ledPin, LOW); // Apagamos el led desde que carga el programa
}

void loop() {
  // put your main code here, to run repeatedly:
  while (digitalRead(sensorPin) == LOW); // mientras el sensor detecte algo
    
  digitalWrite(ledPin, !digitalRead(ledPin)); // se enciende el led con "!" y cambia el estado del led a encendido
  delay(200); // se espera 200 milisegundos
}
