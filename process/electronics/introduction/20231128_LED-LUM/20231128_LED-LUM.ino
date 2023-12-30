#define LED 13
#define BUTTON_PIN 8

float lum = 15;


void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  // put your setup code here, to run once:
}

void loop() {

  boolean btnDown = !digitalRead(BUTTON_PIN);

  if (btnDown) {
    lum = lum + 0.1;
    if (lum>20){
      lum=0;
    }
  }

  digitalWrite(LED, HIGH);
  delay(lum);
  digitalWrite(LED, LOW);
  delay(20 - lum);
}
