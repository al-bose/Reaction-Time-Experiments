int ledPin = 8;
int buttonPin = 2;
int time1 = 0;
int time2 = 0;
int elapsed = 0;



void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);

}

void loop() {

  //delay of 1-4 seconds per flash randomly distributed
  delay(random(1000,4000));
  time1 = millis();
  digitalWrite(ledPin,HIGH);

  while(digitalRead(buttonPin) != HIGH){
  }

  time2 = millis();
  elapsed = time2 - time1;
  Serial.println(elapsed);
  digitalWrite(ledPin,LOW);
}
