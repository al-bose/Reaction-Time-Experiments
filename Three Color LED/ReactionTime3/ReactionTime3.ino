int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int redButton = 2;
int greenButton = 4;
int blueButton = 7;
int time1 = 0;
int time2 = 0;
int elapsed = 0;
int color = 0;



void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(redButton, INPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(greenButton, INPUT);
  pinMode(bluePin, OUTPUT);
  analogWrite(redPin,0);
  analogWrite(greenPin,0);
  analogWrite(bluePin,0);

}

void loop() {

  //delay of 1-4 seconds per flash randomly distributed
  delay(random(1000,4000));
  color = random(0,3);

  if(color == 0){
    analogWrite(redPin, 255);
  }
  else if(color == 1){
    analogWrite(greenPin, 255);
  }
  else if(color == 2){
    analogWrite(bluePin, 255);
  }

  time1 = millis();

  if(color == 0){
    while(digitalRead(redButton) != HIGH){}
  }
  else if(color == 1){
    while(digitalRead(greenButton) != HIGH){}
  }
  else if (color == 2){
    while(digitalRead(blueButton) != HIGH){}
  }
  
  time2 = millis();
  elapsed = time2 - time1;
  Serial.println(elapsed);
  analogWrite(redPin,0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}
