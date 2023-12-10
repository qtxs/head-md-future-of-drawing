#define BUTTON_PIN 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("hello world");

  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {

  boolean btn = digitalRead(BUTTON_PIN);
  //Serial.print("Buton is ");

  int freq = 1;
  Serial.print(sin(TWO_PI * freq * millis() / 2000));
  Serial.print("\t");
  Serial.print(btn);
  Serial.println();

  delay(100);
}
