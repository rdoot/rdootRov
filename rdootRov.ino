#include <Servo.h> 
#include <Ping.h>

Ping ping = Ping(10,74,29); 
Servo myservo;
int M2 = 7;
int E2 = 6;

int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(13);  // attaches the servo on pin 9 to the servo object 
    Serial.begin(9600);
  pinMode(M2, OUTPUT);
  
} 

void loop() {
  
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
   
   int value;
   for(value = 0; value <= 255; value+=5) {
     digitalWrite(M2,HIGH);
     analogWrite(E2, value);
     delay(30);
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
