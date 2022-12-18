#include<Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
int numero = 0;
float firstN;
float secondN;
float resultN;
String operatorN;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Ingresa el 1er #");
  while (Serial.available() == 0);{
  
  }
  delay(3000);
  firstN = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Ingresa el 2do #");
  while (Serial.available () == 0); {
  
  }
  delay(3000);
  secondN = Serial.parseFloat();
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Que operacion?");
  lcd.setCursor(0,1);
  lcd.print("    + - / *   ");
  delay(3000);  
  while (Serial.available ()== 0); {
  
  }
  operatorN = Serial.readString();
  lcd.clear();

    if(operatorN == "+"){
      resultN = firstN + secondN;
    }

    if(operatorN == "-"){
      resultN = firstN - secondN;
    }

    if(operatorN == "*"){
      resultN = firstN * secondN;
    }

    if(operatorN == "/"){
      resultN = firstN / secondN;
    }


  lcd.setCursor(0,0);
  lcd.print("Tu operacion es:");
  lcd.setCursor(0,1);
  lcd.print(firstN);
  lcd.print(operatorN);
  lcd.print(secondN);
  lcd.print("=");
  lcd.print(resultN);
  delay(10000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gracias");
  lcd.setCursor(0,1);
  lcd.print("Vbeta 0.2");
  delay(2000);
  lcd.clear();
}

