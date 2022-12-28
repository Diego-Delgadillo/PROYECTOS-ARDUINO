int pirPin = 2; // Pin del sensor de Infrarrojo activo
int ledPin = 13; // pin del LED
int buzzPin =  4;// pin del buzzer
int toneVal; // Variable del tono del buzzer 
int sinVal;// variable de la funcion matematica SENO para la alarma
int state = 0; // varible del estado del sensor


void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzPin, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(pirPin);// el estado es igual a lso datos que envia el sensor


  if (state == HIGH){ // Si el sensor se aciva, entonces:
    digitalWrite(ledPin, HIGH);// Prende el LED
   // delay(500);
    //digitalWrite(ledPin, LOW);
       for(int x=0; x<180; x++){// Esto ativa una alarma producida por el buzzer
            // convertimos grados en radianes para luego obtener el valor.
            sinVal = (sin(x*(3.1412/180)));
            // generar una frecuencia a partir del valor sin
            toneVal = 2000+(int(sinVal*1000));
            tone(buzzPin, toneVal);
            delay(2); 
     }   


  }
  else{// si no, entonces:
    digitalWrite(ledPin, LOW); // apaga el LED
    digitalWrite(buzzPin, LOW); // apaga el buzzer
    toneVal = 0;
  }


}

