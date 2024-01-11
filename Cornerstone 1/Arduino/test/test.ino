float getdistance();


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float distance = getdistance();
  Serial.println(distance);
  delay(50);
}

float getdistance() {
   float echoTime;
   
   digitalWrite(12, HIGH);
   delayMicroseconds(10);
   digitalWrite(12, LOW);
    
   echoTime = pulseIn(11, HIGH) / 148.0;
   return echoTime;
}
