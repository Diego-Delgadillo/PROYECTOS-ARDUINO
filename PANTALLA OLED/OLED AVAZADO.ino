#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "imagen.h"

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

  //Mostrar logo de inicio
    
  display.clearDisplay();
  display.display();
  delay(1000);

  display.clearDisplay();
  display.drawBitmap(0,0, epd_bitmap_LOGO, 128, 64, WHITE);
  display.display();
  delay(5000);

}

void loop() {
  // put your main code here, to run repeatedly:

  display.display();// muestra lo indicado
  display.clearDisplay();// limpia la pantalla o el bufer


  //Cuadrado base 
  display.fillRect(20, 30 ,100, 10, WHITE);
  display.display();
  delay(2000);

  //Círculo blanco
  display.fillCircle(40, 35, 10, WHITE);
  display.display();
  delay(2000);

  //Círculo negro
  display.fillCircle(70, 35, 10, BLACK);
  display.display();
  delay(2000);

  //Círculo invertido
  display.fillCircle(100, 35, 10, INVERSE);
  display.display();
  delay(2000);

  // Texto
  display.setTextColor(WHITE);// Establecemos el color del texto a mostrar 
  display.setTextSize(1);
  display.clearDisplay();// limpiamos la pantalla
  display.setCursor(50, 32);// ubicamos las coordenadas de nuestro texto
  display.println("Hola mundo"); // Escribimos el mensaje a enviar
  display.display(); // mostramos lo anterior
  delay(2000); // Espera 2 segundos

  display.setTextColor(WHITE);// Establecemos el color del texto a mostrar 
  display.setTextSize(2);
  display.clearDisplay();// limpiamos la pantalla
  display.setCursor(0,0);// ubicamos las coordenadas de nuestro texto
  display.println("Hola mundo"); // Escribimos el mensaje a enviar
  display.display(); // mostramos lo anterior
  delay(2000); // Espera 2 segundos

    // Para mostrar signos especiales
  display.setTextColor(WHITE);// Establecemos el color del texto a mostrar 
  display.setTextSize(1);
  display.clearDisplay();// limpiamos la pantalla
  display.setCursor(0, 0);// ubicamos las coordenadas de nuestro texto
  display.write(164);// insertamos el simbolo especial en codigo ascci
  display.write(64);
  display.write(0176);
  display.display(); // mostramos lo anterior
  delay(2000); // Espera 2 segundos

  // Mostrar todos los caracteres disponibles
  display.clearDisplay();
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.cp437(true);

 for(int16_t i=0; i<256; i++)
  {
    if(i == '\n')
    {
      display.write(' ');
    }
    else
    {
      display.write(i);
    }
  }

  display.display();
  delay(4000);

  //Desplazar texto
  display.setTextColor(WHITE);// Establecemos el color del texto a mostrar 
  display.setTextSize(1);
  display.clearDisplay();// limpiamos la pantalla
  display.setCursor(0, 0);// ubicamos las coordenadas de nuestro texto
  display.println("Prueba de Scroll");
  display.display();
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  display.stopscroll();
  display.startscrolldiagright(0x00, 0x07);
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07);
  delay(2000);
  display.stopscroll();
  delay(1000);
}
