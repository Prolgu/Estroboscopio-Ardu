 ArduScopio: Un estroboscopio implementado en Arduino.
-------------------


**Contiene:**

- Funcion para generar el pulso.
- Frecuencia del pulso controlada por
 potenciometro.
- Impresion en terminal el calculo de RPM. 
- Trigger para impresion serial.

**Falta por definir:**
- Implementación de LCD

## Funcionamiento
Basicamente se usa el ejemplo "Blink", solo que se creó una funcion con dos parametros.
Estos son: el pin en el que arduino va a escribir un estado logico y el delay en el que 
ese estado logico se cambia de alto a bajo para encender o apagar el led.
De momento se utilizó un delay entre 5-200ms, esto seria aproximadamente 200-12000RPM.
Todavia falta comprobarlo en un sistema en movimiento. 
