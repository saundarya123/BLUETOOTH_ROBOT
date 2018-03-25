int isObstaclePin=7;
int isObstacle=HIGH;
int ledPin = 13;  // use the built in LED on pin 13 of the Uno
char state = 0;
int flag = 0;        // make sure that you return the state only once
//L293D
//Motor A
const int motorPin1  = 5;  // Pin 14 of L293
const int motorPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorPin3  = 10; // Pin  7 of L293
const int motorPin4  = 9;  // Pin  2 of L293
const int pingPin=7;
const int echoPin=6;

void setup() {
  // put your setup code here, to run once:
    // sets the pins as outputs:
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
    pinMode(motorPin1, OUTPUT);
    pinMode(motorPin2, OUTPUT);
    pinMode(motorPin3, OUTPUT);
    pinMode(motorPin4, OUTPUT);
    Serial.begin(9600); // Default connection rate for my BT module
  // put your setup code here, to run once:
pinMode(isObstaclePin,INPUT);
Serial.begin(9600);
 Serial.begin(9600);
 pinMode(pingPin,OUTPUT);
 pinMode(echoPin,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
 //if some data is sent, read it and save it in the state variable
    if(Serial.available() > 0){
      state = Serial.read();
      flag=0;
      Serial.println(state);
    }
    // if the state is 0 the led will turn off
    if (state == '0') {
        digitalWrite(ledPin, LOW);
        if(flag == 0){
          Serial.println("LED: off");
          flag = 1;
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
        }
    }
    // if the state is 1 the led will turn on
    if (state == '1') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          Serial.println("LED: on");
          flag = 1;
    digitalWrite(motorPin1,LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
        }
    }
        if (state == '2') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          Serial.println("LED: on");
          flag = 1;
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
        }
    }
        if (state == '3') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          Serial.println("LED: on");
          flag = 1;
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
        }
    }
        if (state == '4') {
        digitalWrite(ledPin, HIGH);
        if(flag == 0){
          Serial.println("LED: on");
          flag = 1;
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
        }
    }
  // put your main code here, to run repeatedly:
isObstacle = digitalRead(isObstaclePin);
if (isObstacle==HIGH)
{
  Serial.println("OBSTACLE!!,WARNING");
}
else
{
  Serial.println("Move and rock!");
}
delay(200);
digitalWrite(pingPin,LOW);
delayMicroseconds(2);
digitalWrite(pingPin,HIGH);
delayMicroseconds(10);
digitalWrite(pingPin,LOW);
int duration=pulseIn(echoPin,HIGH);
int distance_cm=microsecondsToCentimeters(duration);
Serial.print(distance_cm);
Serial.print("cm");
Serial.println();
delay(100);
}long microsecondsToCentimeters(long microseconds)
{
  return(microseconds*0.0341)/2;
}
