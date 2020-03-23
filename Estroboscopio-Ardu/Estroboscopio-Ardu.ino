/*
  -De base estoy utilizando un arduino mega 2560 la idea general
  seria utilizar un arduino nano, con eso se podria crear un dispositivo
  como los que se pueden encontrar en el mercado(tipo pistola de lectura)
  
  -En el A0 conectamos el el cursor del potenciometro (pata central)
  las otras dos patas van conectadas a GND y +5V del Arduino
  con map() en el A0 usamos el DAC propio de arduino para
  convertir una tension analogica en datos digitales.
  De esta forma podemos operar pasando el dato leido a una variable
  que va a ser la que genere el delay entre un estado bajo y alto
  del led (ledPin=13)
  
  -El dato analogico va a ser convertido a digital; entre 0-1023 siendo 
  equivalente a 5-200ms.
  
  -La funcion para imprimir evalua el valor en el pin 2(botonPin), por defecto dejo activado 
  el pullup interno para evitar que actue erroneamente dando lecturas sin
  que se le pida. Si el estado es bajo en el boton, imprime mediante el serial 
  el valor de las rpm.
  
  -Al conectarse el terminal serial mando la cadena Estroboscopio-Ardu
  de esta forma me aseguro de la correcta conexion con el pc;
  estoy pensando implementar el uso de una sola libreria (Wire.h) para imprimir en
  un lcd, por medio del protocolo I2C.
*/

//el led va a ser cambiado despues de probar el correcto funcionamiento del programa
//de momento solo esta puesto en el pin 13 para aprovechar el led que arduino ya trae.

//Definicion de variables e inicializacion de valores
const int ledPin = 13;//constantes
const int botonPin = 2;//constantes
const int sensorPin = A0;//contantes
int poteValor = 0;
float freq = 0;
float valorSalida = 0;

void setup() {
 pinMode(ledPin, OUTPUT); //defino ledPin como salida
 pinMode(botonPin, INPUT_PULLUP); //defino botonPin como entrada y activo el pullup interno (A ser implementado)
 Serial.begin(9600);   // inicializa el serial para mandar datos
   while (!Serial) {
    ;
    }

  // Titulo con salto de linea
  Serial.println("Estroboscopio-Ardu");
}

void loop() {

  poteValor = analogRead(sensorPin);
  valorSalida=map(poteValor,0,1023,5,200);//divido el valor del pote en  1024 partes equivalentes a 5-200ms
  Generador(ledPin,valorSalida);//llamo a la funcion y le doy los argumentos
 // Serial.print("RPM = ");
  //freq = (1000)/(valorSalida+1);
  //Serial.println(60*freq);
  Impresion();
  
}

//con esta funcion gneramos un puso cuadrado.
// Generador(pin,int.)
void Generador(int a,int b)//defino la funcion Generador con
{// a y b como parametros del pin y del delay

  digitalWrite(a,1);//escribo un estado alto en el pin
  delay(b);//espero b ms
  digitalWrite(a,0);//escribo un estado bajo en el pin
  delay(b);//espero b ms

}

  void Impresion()
 {
 boolean buttonState = digitalRead(botonPin);

  // Chequea el push button.
  if (buttonState == LOW) {
      Serial.print("RPM = ");
      freq = (60000)/(valorSalida);
      Serial.println(freq);
  } 
  else {
  //delay(1);
  }
   }
