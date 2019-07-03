/*
  Developed by : R.Gnana Sreekar
  On : 2 July 2019
  Github : https://github.com/gnanasreekar
  Linkdin : https://www.linkedin.com/in/gnana-sreekar/
  Instagram : https://www.instagram.com/gnana_sreekar/
*/
#include <SoftwareSerial.h>
SoftwareSerial BT(2,4);
String command;
void setup()
{
 BT.begin(9600);
 Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop() {
  while (BT.available()){ 
  delay(10);
  char bt = BT.read();
  command += bt; 
  } 
  if (command.length() > 0) {
    Serial.println(command);
  if(command == "Light_on")
  {
    digitalWrite(8, HIGH);
  }
  else if(command == "Light_off")
  {
    digitalWrite(8, LOW);
  }
  else if (command == "Fan_on")
  {
    digitalWrite (9, HIGH);
  }
  else if ( command == "Fan_off")
 {
   digitalWrite (9, LOW);
 }
 else if ( command == "All_off")
 {
   digitalWrite(8, LOW);
   digitalWrite (9, LOW);
 }
 else if (command == "All_on")
  {
    digitalWrite (9, HIGH);
    digitalWrite (8, HIGH);

  }

command="";
}
}
