//still a work in progress
int trigPin=11; //Connect sensor trig pin to arduino
int echoPin = 10; // connection sensor pin
float pingTime;//declare measured ping time
float targetDistance;//distance to target in inches
float speedOfSound = 776.5;//speend of sound
void setup() {
  Serial.begin(9600);//starting serial monitor
  pinMode(trigPin,OUTPUT);//set trigger pin
  pinMode(echoPin,INPUT); //set echo pin
  pinMode(6,OUTPUT);
  
}
void loop() {
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);

  
  pingTime = pulseIn(echoPin,HIGH);
  pingTime=pingTime/1000000.;
  pingTime=pingTime/3600.;
  targetDistance=speedOfSound*pingTime;
  targetDistance = targetDistance/2;
  targetDistance = targetDistance*63360;
  Serial.println(targetDistance);


  while(targetDistance > 72){
    digitalWrite(6,HIGH);
    delayMicroseconds(500);
    digitalWrite(6,LOW);
    delayMicroseconds(500);
  }
} 
