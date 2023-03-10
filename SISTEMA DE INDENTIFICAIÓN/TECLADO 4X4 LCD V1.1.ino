#include <Key.h>// Librerías necesarias para poder usar el teclado 4x4
#include <Keypad.h>
#include <LiquidCrystal_I2C.h> 
LiquidCrystal_I2C lcd(0x27,16,2);// Configuramos el LCD

char myChar = 0xEE; // esta variable de tipo carácter nos permite mostrar la letra ñ 
int buzzPin = 13; 
const byte filas = 4; // Aqui esta la varibal qe declaramos para indicar la cantidad de columnas
const byte columnas = 4; // varibale cantidad de columnas 
byte pinsFilas [filas] = {11, 10, 9, 8}; // indicamos los pines de las filas
byte pinsColumnas [columnas] = {7, 6, 5, 4}; // indicamos pines de las columnas
int tecla = 0;
int menu_nivel = 0;
int valor = 0;
int numero = 0;
char opcion_seleccionada = ' '; // Variable de tipo caracter para lo que se presione en el teclado

char teclas [filas] [columnas] = {
  {'1', '2',  '3', 'A'},// Matriz del teclado
  {'4', '5',  '6', 'B'},
  {'7', '8',  '9', 'C'},
  {'*', '0',  '#', 'D'},

};

Keypad teclado = Keypad(makeKeymap(teclas), pinsFilas, pinsColumnas, filas , columnas); //Se crea un objeto con ayuda de una funcion

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {

   lcd.clear();
  if(menu_nivel == 0){
    lcd.setCursor(1,0);    
    lcd.print("Selecciona una");// Este es el menu que se muestra en el LCD al iniciar el PROGRAMA
    lcd.setCursor(0,1);
    lcd.print("opcion (A,B,C,D)");

    tecla = 0;
    while(tecla == NULL){ // Mientras la varibale de tecla no tenga nigun valor, entonces:
      tecla = teclado.getKey(); // Obtiene una de las letras (A,B,C,D)
        if(tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D' ){
          opcion_seleccionada = tecla; // Asignamos el valor de una de las letras
          menu_nivel = 1;
          digitalWrite(buzzPin, HIGH); // Esto es para activar el sonido al momento de presionar una tecla
          delay(100);
          digitalWrite(buzzPin, LOW);          
        }
    }
  }

  if (opcion_seleccionada != ' '){
    switch(opcion_seleccionada){ // Aqui se muestran cada uno de los casos por letra
      case 'A':
        opcion_a();
        break;

      case 'B':
        opcion_b();
        break;

      case 'C':
        opcion_c();
        break;

      case 'D':
        opcion_d();
        break;
    }
  }
}

void opcion_a() { // funcion de la opción A
  valor = 0;
  tecla = 0;
  lcd.clear();
  lcd.home();
  lcd.print("Cual es tu edad?");
  lcd.setCursor(0,1);
  while(tecla != '#'){ // Con esta tecla capturamos los valores que tecleamos 
    tecla =  teclado.getKey(); // Obtiene la tecla que presionamos 
    if(tecla != NO_KEY){
      digitalWrite(buzzPin, HIGH); // Esto es para activar el sonido al momento de presionar una tecla
      delay(100);
      digitalWrite(buzzPin, LOW);
      if((tecla >= '0') && (tecla <= '9')){ // esto es para que solo ingresemos números del 1 al 9
        digitalWrite(buzzPin, HIGH); // Esto es para activar el sonido al momento de presionar una tecla
        delay(100);
        digitalWrite(buzzPin, LOW);
        valor = (valor*10) +  tecla - 48; // esto hace que se muestre el numero en la pantalla
        lcd.print(tecla-48);
      }
    }
  }
  menu_nivel = 0;
}

void opcion_b() { // funcion de la opcion B
  lcd.clear();  
  lcd.home();
  lcd.setCursor(3,0);
  lcd.print("Ingresaste: "); 
  lcd.setCursor(4,1); // esto centra el texto
  lcd.print(valor); // Muestra el valor capturado
  lcd.print(" A");
  lcd.print(myChar);
  lcd.print("os");
  delay(3000);
  menu_nivel = 0; // regresa al menú 0
}

void opcion_c() { // funcion de la opcion C
// Estas variables son para el desplazamiento del texto
String mensaje = "Ingresar genero (1=Hombre, 2=Mujer)";
int longitud_texto = mensaje.length();
int posicion;
  Serial.begin(9600);
  valor = 0;
  tecla = 0;
  lcd.clear();
  lcd.home();
  lcd.setCursor(0,0);
  lcd.print(mensaje);
  delay(1000);
  for (posicion = 0; posicion<longitud_texto; posicion++){ // Esto es para desplazar el texto hacia la izquierda
    lcd.scrollDisplayLeft();
    delay(300);
    } 
  lcd.setCursor(0,1);
  while(tecla != '#'){ // Con esta tecla capturamos los valores que tecleamos 
    tecla =  teclado.getKey(); // Obtiene la tecla que presionamos 
    if(tecla != NO_KEY){
      digitalWrite(buzzPin, HIGH); // Esto es para activar el sonido al momento de presionar una tecla
      delay(100);
      digitalWrite(buzzPin, LOW);
      if((tecla >= '1') && (tecla <= '2')){ // esto es para que solo ingresemos números del 1 al 9
        digitalWrite(buzzPin, HIGH); // Esto es para activar el sonido al momento de presionar una tecla
        delay(100);
        digitalWrite(buzzPin, LOW);
        valor = (valor*10) +  tecla - 48; // esto convierte de codigo ASCCI a un nuemro normal por eso multiplica por 458
        lcd.print(tecla-48);
        Serial.print(valor);
      }
    }
  }
  menu_nivel = 0;
}

void opcion_d() { // funcion de la opcion D
  lcd.clear();  
  lcd.home();
  lcd.setCursor(3,0);
  lcd.print("Ingresaste: "); 
  
  if (valor == 1){
      lcd.setCursor(5,1);
      lcd.print("Hombre");
      delay(3000);
      menu_nivel = 0;
  }

   if (valor == 2){
      lcd.setCursor(6,1);
      lcd.print("Mujer");
      delay(3000);
      menu_nivel = 0;
  }

}