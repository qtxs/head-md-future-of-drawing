#define PIEZO 11
int freq = 1000;
int sound = 2000;




void setup() {
  pinMode(PIEZO, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  int value = analogRead(A0);
  freq = map(value, 0, 1023, 1000, 0);
  sound = map(value, 0, 1023, 2000, 0);
  // Serial.println(value);

  // digitalWrite(PIEZO, HIGH);
  // delay(sound);
  // digitalWrite(PIEZO, LOW);
  // delay(20 - sound);

  tone(PIEZO, freq, sound);

  //delay(2000);

  //tone(PIEZO, sound);
  //delay(1000);
  noTone(PIEZO);

  //delay(1000);
}
