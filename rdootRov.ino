#include <Servo.h> 
#include <Ping.h>

Ping ping = Ping(10,74,29); 
Servo myservo;

int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object 
    Serial.begin(9600);
} 

void loop(){
  
Serial.println(" | Microseconds: ");
Serial.print(ping.microseconds());
   ping.fire();
   delay(500);
   
   if(ping.microseconds()<500){
     left();
     Serial.print("left");
   }
   else {
     straight();
   }
} 
void straight(){
  delay(15); 
  myservo.write(79);              // tell servo to go to position in variable 'pos' 
 
}
void left(){
  delay(15); 
  myservo.write(59);              // tell servo to go to position in variable 'pos' 
 
}
void right(){
  myservo.write(99);              // tell servo to go to position in variable 'pos' 
    delay(15);  
}
