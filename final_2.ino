
#include <SoftwareSerial.h>
#include <NewPing.h>
#include <Servo.h>

#define Trigger 10
#define Echo 11
#define MaxDistance 69

SoftwareSerial mySerial(2, 3); //RX, TX
NewPing sonar(Trigger, Echo, MaxDistance);
int servoPin = 9;
Servo Servo_1;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  Servo_1.attach(servoPin);
}

void loop() {

   Servo_1.write(90);
  
  if(Serial.available() > 0){//Read from serial monitor and send over HC-12
    String input = Serial.readString();
    mySerial.println(input);    
  }
 
  if(mySerial.available() > 1){//Read from HC-12 and send to serial monitor
    //String input = mySerial.readString();
    char c = mySerial.read();
    Serial.println(c);
    if(c =='1')//ahead
    { 
      if (sonar.ping_cm()!=0 && sonar.ping_cm()<50){  
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      
      }
      else 
      {
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(7,1);
      delay(1000);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
        }
    }
    if(c=='2')//back
    {
        digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(6,1);
      digitalWrite(7,0);
      delay(1000);
        digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
    if(c=='3')//left
    {  
      Servo_1.write(180);
    delay(1000);
Serial.print(sonar.ping_cm());
      if(sonar.ping_cm()!=0){
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
      else{
       digitalWrite(4,1);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,1);
      delay(380);
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(7,1);
      delay(620);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
    }
      if(c=='4')//right
    {
       Servo_1.write(0);
    delay(1000);
Serial.print(sonar.ping_cm());
      if(sonar.ping_cm()!=50) {
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
      else{
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(6,1);
      digitalWrite(7,0);
      delay(440);
      digitalWrite(4,0);
      digitalWrite(5,1);
      digitalWrite(6,0);
      digitalWrite(7,1);
      delay(560);
      digitalWrite(4,0);
      digitalWrite(5,0);
      digitalWrite(6,0);
      digitalWrite(7,0);
      }
    }
  }    
delay(20);

}
