const int ledPin = 13;//constantes
const int botonPin = 2;//constantes


void setup() {
 pinMode(ledPin, OUTPUT); //defino ledPin como salida
 pinMode(botonPin, INPUT); //defino botonPin como entrada
 Serial.begin(9600);   // inicializa el serial para mandar datos
   while (!Serial) {
    ; 
    }

  // Titulo con salto de linea
  Serial.println("Estroboscopio");
}

void loop() {

  int poteValor = analogRead(A0);
  int delay_ms=map(poteValor,0,1023,10,150);//divido el valor del pote en  1024 partes equivalentes a 10-150ms
  Generador(ledPin,delay_ms);//llamo a la funcion y le doy los argumentos
  //delay(1000);
  Serial.print(delay_ms);//imprimo en la terminal el valor en ms
  //Serial.println(" Rpm");// para cuando haga la conversion
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
