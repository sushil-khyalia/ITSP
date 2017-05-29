#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //RX, TX
SoftwareSerial hc05(10, 11);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  hc05.begin(38400);
}

char voice ;
void loop() {

// Serial.println("hello");

  while (hc05.available()){ //Check if there is an available byte to read
     delay(10); //Delay added to make thing stable 
     voice = hc05.read();
     Serial.print("voice  :");
     Serial.println(voice);
  }
  if (voice > 0){
    if(voice == '1'){
      //delay(1000);
      mySerial.println(voice); 
      Serial.println("aage chal bhosdike");
      }
    else if(voice == '2'){
      mySerial.println(voice); 
      Serial.println("ulta chal bhosdike");
      }
    else if(voice == '3'){
      mySerial.println(voice); 
      Serial.println("ghoom bhosdike");
      }
    else if(voice == '4'){
      mySerial.println(voice); 
      Serial.println("ulta ghoom bhosdike");
      }
    else if(voice == '5'){
      mySerial.println(voice); 
      Serial.println("aage mat chal bhosdike");
      }
    voice=0; //Reset the variable after initiating
  }


  
  if(Serial.available() > 0){//Read from serial monitor and send over HC-12
    String input = Serial.readString();
    mySerial.println(input);     
  }
 
  if(mySerial.available() > 1){//Read from HC-12 and send to serial monitor
    String input = mySerial.readString();
    Serial.println(input); 
  }
  delay(20); 
}
