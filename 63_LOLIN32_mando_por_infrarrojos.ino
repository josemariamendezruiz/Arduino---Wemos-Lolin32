/*
    MANDO TECLADO POR INFRARROJOS Y ENCIENDE LEDS
    AUTOR : JOSE MARIA MENDEZ RUIZ
    ENERO 2025
    CODIGO LIBRE PARA UTILIZAR COMO QUIERAS

    Librería ( Armin Joachimsmeyer )
    https://www.arduinolibraries.info/libraries/i-rremote    
*/

#include <IRremote.h>                   // Para utilizar el receptor por infrarrojos

// DECLARAMOS LAS VARIABLES QUE VAMOS A UTILIZAR
int Pin_Lector = 15;          // El Pin donde conectaremos la entrada de datos del sensor

IRrecv irrecv(Pin_Lector);               // Creamos el objeto para el sensor infrarrojos
decode_results results;                  // Le asignamos a results la decodificacion de lo que se recibe, hay diferentes decodificaciones , según el fabricante

void setup() {   
  Serial.begin(9600);
  irrecv.enableIRIn();                  // Habilitamos el receptor de infrarrojos   
  // Los Pines donde conectaremos las salidas para activar los leds o lo que queremos controla
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  String Tecla;   // Guardamos en la variable Tecla el valor de la tecla que se ha pulsado
  // SI SE RECIBEN DATOS PROCEDEMOS A SU ANALISIS, USAREMOS LA CODIFICACION QUE MAS NOS INTERESE, EN NUESTRO CASO USAREMOS HEXADECIMAL
  if (irrecv.decode()) {
        // Con la siguiente línea veremos en el monitor serie lo que recibimos, una vez identificada todas las teclas que correspondan bien a lo que se pulsa, la siguiente línea la podemos borrar y solo saldra en pantalla la tecla pulsada.
        Serial.println(irrecv.decodedIRData.command); // Mostramos lo leido en el monitor serie para identificar los códigos que recibimos de nuestro teclado infrarrojos y los ajustamos a las teclas a continuación que se indican en el código
               
        // Aqui ajustamos los valores-+ recibidos al valor que cada tecla, de forma que si es diferente lo que recibimos de nuestro teclado, tan solo tenemos que poner el código que recibimos a que tecla corresponde
        // Tener en cuenta que no pueden repetirse los valores HEX, es decir cada tecla siempre será diferente en su valor HEX, nunca habra dos teclas con el mismo valor
        switch(irrecv.decodedIRData.command)
        {
          case 25: Tecla = "Tecla: 0"; digitalWrite(0,HIGH);delay(1000);
                       break;
          case 69: Tecla = "Tecla: 1"; digitalWrite(1,HIGH);delay(1000);
                      break;
          case 70: Tecla = "Tecla: 2"; digitalWrite(2,HIGH);delay(1000);
                      break;
          case 71: Tecla = "Tecla: 3"; digitalWrite(3,HIGH);delay(1000);
                       break;
          case 68: Tecla = "Tecla: 4"; digitalWrite(4,HIGH);delay(1000);
                       break;
          case 64: Tecla = "Tecla: 5";
                       break;
          case 67: Tecla = "Tecla: 6";
                       break;
          case 7: Tecla = "Tecla: 7";
                       break; 
          case 21: Tecla = "Tecla: 8";
                       break;
          case 9: Tecla = "Tecla: 9";
                       break;
          case 22: Tecla = "Tecla: *";
                       break;
          case 13: Tecla = "Tecla: #";
                       break;
          case 24: Tecla = "Tecla: Arriba";
                       break;
          case 8: Tecla = "Tecla: Izquierda";
                       break;
          case 90: Tecla = "Tecla: Derecha";
                       break;
          case 82: Tecla = "Tecla: Abajo";
                       break;
          case 28: Tecla = "Tecla: Ok";
                       break;
    }
    Serial.println(Tecla);
    digitalWrite(0,LOW);
    digitalWrite(1,LOW);
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);

    irrecv.resume();     // empezamos a recibir de nuevo
  }
  delay(100); // Definimos cada cuanto leeremos los valores, en este caso cada 100 milisegundos
}
