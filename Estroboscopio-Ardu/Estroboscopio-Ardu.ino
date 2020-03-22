//De base estoy utilizando un arduino mega 2560 la idea general 
//seria utilizar un arduino nano, con eso se podria crear un dispositivo
//como los que se pueden encontrar en el mercado(tipo pistola de lectura)
//En el A0 conectamos el el cursor del potenciometro (pata central)
//las otras dos patas van conectadas a GND y +5V del Arduino
//con map() en el A0 usamos el DAC propio de arduino para
//convertir una tension analogica en datos digitales
//de esta forma podemos operar pasando el dato leido a una variable
//que va a ser la que genere el delay entre un estado y alto
//del led (ledPin=13)
//el dato analogico va a ser entre 0-1023 siendo equivalente a 10-150ms
//todavia sigo trabajando en la mejor forma de que el serial
//solo imprima cuando se lo ordene por medio de un boton (botonPin)
//al conectarse el terminal serial mando la cadena Estroboscopio-Ardu
//de esta forma me aseguro de la correcta conexion con el pc
//estoy ppensando implementar el uso de una sola libreria para imprimir en
//un lcd, por medio del protocolo I2C.




const int ledPin = 13;//constantes
const int botonPin = 2;//constantes
const int sensorPin = A0;
int poteVuualor = 0;
float freq = 0;
float valorSalida = 0;

void setup() {
 pinMode(ledPin, OUTPUT); //defino ledPin como salida
 pinMode(botonPin, INPUT); //defino botonPin como entrada
 Serial.begin(9600);   // inicializa el serial para mandar datos
   while (!Serial) {
    ;
    }

  // Titulo con salto de linea
  Serial.println("Estroboscopio-Ardu");
}

void loop() {

  poteValor = analogRead(sensorPin);
  valorSalida=map(poteValor,0,1023,10,150);//divido el valor del pote en  1024 partes equivalentes a 10-150ms
  Generador(ledPin,valorSalida);//llamo a la funcion y le doy los argumentos
  Serial.print("RPM = ");
  freq = (1000)/(valorSalida+1);
  Serial.println(60*freq);
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
