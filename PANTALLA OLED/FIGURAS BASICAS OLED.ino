/*
CODE BY: DIEGO RICARDO DELGADILLO GOMEZ
FOR MORE INFORMATION ABOUT CONNECTIONS:
ARDUINO: https://circuitdigest.com/microcontroller-projects/arduino-ssd1306-oled-display
ESP32: https://www.electronicshub.org/esp32-oled-display/ 
IMPORTANT: This example was made for ESP32 if you are working with Arduino visit the links
DATE: 25/12/2022
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_MOSI   23
#define OLED_CLK    18
#define OLED_DC     16
#define OLED_CS     5
#define OLED_RESET  17

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // Esto es para incializar la pantalla y ver si esta funcionando el display enviando un mensaje a traves del monitor serial
  if(!display.begin(SSD1306_SWITCHCAPVCC))
  {
    Serial.println(F("SSD1306 allocation failed")); // Envia un erro en el monitor serial que esta fallando
    for(;;);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:

  // Dibujar punto
  display.display();// muestra lo indicado
  display.clearDisplay();// limpia la pantalla o el bufer
  display.drawPixel(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, WHITE);
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  //Dibujar linea
  display.clearDisplay();
  display.drawLine(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1, WHITE);// Primero envia la coordenadas luego el larog y ancho y por ultimo el color
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  //Dibujar cuadrado
  display.clearDisplay();
  display.drawRect(20, 20, 30, 30, WHITE);// Envai primero las coordenadas y luego el ancho y largo del cuadrado y por ultimo el color
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  //Dibujar cuadrado relleno
  display.clearDisplay();
  display.fillRoundRect(20, 20, 30, 30, 10, WHITE);
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  // Círculo
  display.clearDisplay();
  display.drawCircle(20, 20, 10, WHITE); // Aqui indicamos primero las coordenadas y luego el rdio y por ultimo el color
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  // Círculo relleno
  display.clearDisplay();
  display.fillCircle(20, 20, 10, WHITE); // Aqui indicamos primero las coordenadas y luego el rdio y por ultimo el color
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  // Triángulo
  display.clearDisplay();
  display.drawTriangle(20, 20, 20, 50, 50, 50, WHITE);// Primero van las coordenadas [X,Y]1 , [X,Y]2 Y [X,Y]3
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

  //Triángulo relleno
  display.clearDisplay();
  display.fillTriangle(20, 20, 20, 50, 50, 50, WHITE);// Primero van las coordenadas [X,Y]1 , [X,Y]2 Y [X,Y]3
  display.display();// Esto sirve para mostrar lo indicado anteriormente
  delay(1000);

}
