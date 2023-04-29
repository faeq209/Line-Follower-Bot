#define Motor1f 7
 #define Motor1b 6
 #define Motor2f 8
 #define Motor2b 9
 #define PWMmotor1 5
 #define PWMmotor2 10
 
 int valuePWM1=120; // speed motor 1 
 int valuePWM2=150; // speed motor 2
 
void setup() {
  Serial.begin(9600);
  pinMode(Motor1f,OUTPUT);
  pinMode(Motor1b,OUTPUT);
  pinMode(Motor2f,OUTPUT);
  pinMode(Motor2b,OUTPUT);
  pinMode(PWMmotor1,OUTPUT);
  pinMode(PWMmotor2,OUTPUT);
 
pinMode(A0, INPUT); // initialize Right sensor as an inut
pinMode(A1, INPUT); // initialize Left sensor as as input
 
}
 
void loop() {
 
  int LEFT_SENSOR = analogRead(A0);
  int RIGHT_SENSOR = analogRead(A1);
  Serial.print("Left value:");
  Serial.println(LEFT_SENSOR);
  Serial.print("Right value:");
  Serial.println(RIGHT_SENSOR);
   
  
if(RIGHT_SENSOR<40&& LEFT_SENSOR<40) //FORWARD
{
            digitalWrite(Motor1f, HIGH);
            digitalWrite(Motor1b, LOW);
            digitalWrite(Motor2f, HIGH);
            digitalWrite(Motor2b, LOW);
            analogWrite(PWMmotor1, valuePWM1);
            analogWrite(PWMmotor2, valuePWM1);
}
 
 else if(RIGHT_SENSOR>40 && LEFT_SENSOR<40) //LEFT
 {
            digitalWrite(Motor1b, LOW);
            digitalWrite(Motor1f, HIGH);
            digitalWrite(Motor2b, HIGH);
            digitalWrite(Motor2f, LOW);
            analogWrite(PWMmotor1, valuePWM2);
            analogWrite(PWMmotor2, valuePWM2);
}
 
else if(RIGHT_SENSOR<40 && LEFT_SENSOR>40) //RIGHT
 {
              digitalWrite(Motor1b, HIGH);
              digitalWrite(Motor1f, LOW);
              digitalWrite(Motor2b, LOW);
              digitalWrite(Motor2f, HIGH);
              analogWrite(PWMmotor1, valuePWM2);
              analogWrite(PWMmotor2, valuePWM2);
}
 
else if(RIGHT_SENSOR>40 && LEFT_SENSOR>40) //BACK
{
              digitalWrite(Motor1b, LOW);
              digitalWrite(Motor1f, LOW);
              digitalWrite(Motor2b, LOW);
              digitalWrite(Motor2f, LOW);
              delay(10000);
 }
}
