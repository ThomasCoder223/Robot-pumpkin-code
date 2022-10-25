#include <Servo.h>
#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

Servo servo_8; //left eye
Servo servo_9; //mouth
Servo servo_10; //right eye
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  servo_8.attach(8);
  servo_9.attach(9);
  servo_10.attach(10);
  digitalWrite(4,0);
  digitalWrite(5,0);
  servo_8.write(90);
  servo_9.write(90);
  servo_10.write(76);
  while(1) {
      if(getDistance(7,6) < 50){ // If trigered
          for(int count=0;count<10;count++){ //Repeat 10 times
              digitalWrite(5,1); //Turn on LEDs
              digitalWrite(4,1);
              servo_8.write(100);//Servo motor dance...
              _delay(0.2);
              servo_9.write(100);
              _delay(0.2);
              servo_10.write(87);
              _delay(0.2);
              servo_8.write(80);
              _delay(0.2);
              servo_9.write(80);
              _delay(0.2);
              servo_10.write(65);
              _delay(0.2);
          }
          for(int count2=0;count2<10;count2++){ //Faster end loop
              servo_8.write(80);
              servo_9.write(80);
              servo_10.write(80);
              _delay(0.1);
              servo_8.write(100);
              servo_9.write(100);
              servo_10.write(100);
              _delay(0.1);
          }
          digitalWrite(4,0);
          digitalWrite(5,0);
          _delay(30);

      }

      _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
