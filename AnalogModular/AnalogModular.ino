/*
Arduino Modular Analog Reader
This code will trigger a set of functions. 
The code contains a "Sticky" function that sets it up as an level. Where the previous trigers will also be enabled 
*/

int analogPin = 3;     // potentiometer wiper (middle terminal) connected to analog pin 3
                       // outside leads to ground and +5V
int val = 0;           // variable to store the value read

int Ch1 = 3;
int Ch2 = 4;
int Ch3 = 5;
int Ch4 = 6;
int Ch5 = 7;
int Ch6 = 8;
int Ch7 = 9;
int Ch8 = 10;

int Ch1Trigger = 31;
int Ch2Trigger = 62;
int Ch3Trigger = 93;
int Ch4Trigger = 124;
int Ch5Trigger = 155;
int Ch6Trigger = 186;
int Ch7Trigger = 217;
int Ch8Trigger = 255;

boolean sticky = false; //Enables all the other channels (acts as levels)



void setup()
{
  Serial.begin(9600);//  setup serial
  pinMode(Ch1, OUTPUT);
  pinMode(Ch2, OUTPUT);
  pinMode(Ch3, OUTPUT);
  pinMode(Ch4, OUTPUT);
  pinMode(Ch5, OUTPUT);
  pinMode(Ch6, OUTPUT);
  pinMode(Ch7, OUTPUT);
  pinMode(Ch8, OUTPUT);

}

void loop()
{
  val = analogRead(analogPin);     // read the input pin
  Serial.println(val);// debug value
  
  if (val >= Ch1Trigger)
  {
    digitalWrite(Ch1, HIGH); 
  }else if (val >= Ch2Trigger)
  {
    digitalWrite(Ch2, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
    }
  }else if (val >= Ch3Trigger)
  {
    digitalWrite(Ch1, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
    } 
  }else if (val >= Ch4Trigger)
  {
    digitalWrite(Ch4, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
       digitalWrite(Ch3, HIGH);
    }  
  }else if (val >= Ch5Trigger)
  {
    digitalWrite(Ch5, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
       digitalWrite(Ch3, HIGH);
       digitalWrite(Ch4, HIGH);
    } 
  }else if (val >= Ch6Trigger)
  {
    digitalWrite(Ch6, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
       digitalWrite(Ch3, HIGH);
       digitalWrite(Ch4, HIGH);
       digitalWrite(Ch5, HIGH);
    }  
  }else if (val >= Ch7Trigger)
  {
    digitalWrite(Ch7, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
       digitalWrite(Ch3, HIGH);
       digitalWrite(Ch4, HIGH);
       digitalWrite(Ch5, HIGH);
       digitalWrite(Ch6, HIGH);
    }  
  }else if (val >= Ch8Trigger)
  {
    digitalWrite(Ch8, HIGH);
    if (sticky){
       digitalWrite(Ch1, HIGH);
       digitalWrite(Ch2, HIGH);
       digitalWrite(Ch3, HIGH);
       digitalWrite(Ch4, HIGH);
       digitalWrite(Ch5, HIGH);
       digitalWrite(Ch6, HIGH);
       digitalWrite(Ch7, HIGH);
    }   
  }else
  {
    Serial.println("No Metal Detected");
    digitalWrite(Ch1, LOW); 
    digitalWrite(Ch2, LOW); 
    digitalWrite(Ch3, LOW); 
    digitalWrite(Ch4, LOW); 
    digitalWrite(Ch5, LOW); 
    digitalWrite(Ch6, LOW); 
    digitalWrite(Ch7, LOW); 
    digitalWrite(Ch8, LOW); 
    
  }
}