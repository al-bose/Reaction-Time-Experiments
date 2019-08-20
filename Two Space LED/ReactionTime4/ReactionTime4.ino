int leftLed = 12;
int leftButton = 7;
int rightLed = 8;
int rightButton = 2;
int time1 = 0;
int time2 = 0;
int elapsed = 0;
int ledChoice = 0;



void setup() {
  Serial.begin(9600);
  pinMode(leftLed, OUTPUT);
  pinMode(leftButton, INPUT);
  pinMode(rightLed, OUTPUT);
  pinMode(rightButton, INPUT);
  digitalWrite(leftLed, LOW);
  digitalWrite(rightLed, LOW);

}

void loop() {

  //delay of 1-4 seconds per flash randomly distributed
  delay(random(1000,4000));
  ledChoice = random(0,2);

  if(ledChoice == 0){
    digitalWrite(leftLed, HIGH);
  }
  else if(ledChoice == 1){
    digitalWrite(rightLed, HIGH);
  }

  time1 = millis();

  if(ledChoice == 0){
    while(digitalRead(leftButton) != HIGH){}
  }
  else if(ledChoice == 1){
    while(digitalRead(rightButton) != HIGH){}
  }
  
  time2 = millis();
  elapsed = time2 - time1;
  Serial.println(elapsed);
  digitalWrite(leftLed,LOW);
  digitalWrite(rightLed,LOW);
}
