#define LED 13
int lum = 15;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int value = analogRead(A0);  // will get a value from 0 to 1023
  Serial.println(value);


  lum = map(value, 0, 1023, 20, 0);
  digitalWrite(LED, LOW);
  delay(lum);
  digitalWrite(LED, HIGH);
  delay(20 - lum);
}
