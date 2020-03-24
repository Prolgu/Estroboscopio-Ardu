# Estroboscopio-Ardu


**Primer prueba de funcionamiento, contiene:**

- Funcion para generar el pulso.
- Frecuencia del pulso controlada por
potenciometro.
- impresion en terminal.

**Falta por definir:**
-~~ Imprimir el calculo de RPM.~~
-~~ Posible implementacion de lcd.~~
-~~ Posible trigger para impresion serial.~~

## Funcionamiento
Basicamente se usa el ejemplo "Blink", solo que se crea una funcion con dos parametros.
Estos son: el pin en el que arduino va a escribir un estado logico y el delay en el que 
ese estado logico se cambia de alto a bajo para encender o apagar el led.
De momento utilice entre 10-150ms, esto seria entre 400-6000RPM.
Todavia falta comprobarlo en un sistema en movimiento por que de momento no cuento con 
una forma de hacerlo.
