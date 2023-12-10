#define CONTROL_PIN A0

#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 11

// int RED_PIN = 0;
// int BLUE_PIN = 0;
// int GREEN_PIN = 0;


void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  //pinMode(CONTROL_PIN, OUTPUT);
}

void loop() {
  int value = analogRead(CONTROL_PIN);
  int color = map(value, 0, 1023, 0, 255);
  Serial.println(color);

  //setColor(color, 100,200);
  analogWrite(RED_PIN, color);
  analogWrite(GREEN_PIN, color - 10);
  analogWrite(BLUE_PIN, color + 10);

  delay(100);
}