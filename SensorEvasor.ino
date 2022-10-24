#include <Servo.h> // Incluímos la librerí­a para poder controlar el servo
Servo servoMotor; // Declaramos la variable para controlar el servo
int pinReceptor = A1; //Establecemos el pin a leer
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
boolean leerSensor = true;

void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
servoMotor.attach(9);
servoMotor.write(150);
        }

void loop(){

servoMotor.attach(9);
sensorVal = analogRead(pinReceptor); //Guardamos la lectura del pin Analógico
Serial.println("Analoga:");
Serial.println(sensorVal); //Sacamos la lectura por serial
delay(500); //Pequeña pausa de medio segundo

if (sensorVal <= 45 && leerSensor) {
   if(leerSensor){
     leerSensor = false;
   }
   servoMotor.write(20); // Desplazamos a la posición 0º
   delay(2000);
   servoMotor.write(150); // Desplazamos a la posición 170º
   delay(2000);
   servoMotor.write(20); // Desplazamos a la posición 0º
   delay(2000);
   servoMotor.write(150); // Desplazamos a la posición 170º
   delay(2000);
   leerSensor = true;
   }
}
