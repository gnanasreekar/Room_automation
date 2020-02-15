/*

  Developed by : ℝ.𝔾𝕟𝕒𝕟𝕒 𝕊𝕣𝕖𝕖𝕜𝕒𝕣

  Github : https://github.com/gnanasreekar

  Linkdin : https://www.linkedin.com/in/gnana-sreekar/

  Instagram : https://www.instagram.com/gnana_sreekar/

  Website : https://gnanasreekar.com

*/



char Incoming_value; 
int val1 =0,val2 =0,val3 =0 ;
String change;
void setup() 
{
  
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
 digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  status();
}
void loop()
{
  if(Serial.available() > 0)  
  {
    delay(200);
    Incoming_value = Serial.read();       
    if(Incoming_value == '0') {
      digitalWrite(10, LOW);
      status();
    }      
    else if(Incoming_value == '1'){       
      digitalWrite(10, HIGH);
      status();
    }
    else if(Incoming_value == '2'){       
      digitalWrite(8, LOW); 
      status();
    }
    else if(Incoming_value == '3'){       
      digitalWrite(8, HIGH);  
      status();
    }
     else if(Incoming_value == '4'){       
      digitalWrite(9, LOW); 
      status();
    }
     else if(Incoming_value == '5'){       
      digitalWrite(9, HIGH); 
      status();
    }
    else if(Incoming_value == '6'){       
      digitalWrite(9, LOW);
      digitalWrite(10, LOW);
      digitalWrite(8, LOW); 
      status();
    }
    else if(Incoming_value == '7'){       
      digitalWrite(9, HIGH);
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH); 
      status();
    }
    else if(Incoming_value == '8'){       
      status();
    }
  }                                 
}

void status(){
  val1 = digitalRead(10);
      val2 = digitalRead(8);
      val3 = digitalRead(9);
      if(val1 == LOW){
        change = "1-";
      } else if(val1 == HIGH){
        change = "0-";
      } 
      if(val2 == LOW){
        change = change + "1-";
      } else if(val2 == HIGH){
        change = change + "0-";
      } 
      if(val3 == LOW){
        change = change + "1";
      } else if(val3 == HIGH){
        change = change + "0";
      }
      Serial.print(change); 
      change = "";
}
