#define LED_PIN 13  // define the constant "name" for your pin
#define BUTTON_PIN 8

//boolean val = HIGH;  // HIGH = 1 = ON
// boolean val = digitalRead(BUTTON_PIN);


void setup() {

 

  pinMode(LED_PIN, OUTPUT);
  // pinMode(BUTTON_PIN, INPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(LED_PIN, LOW);  // LED is off when we start
}

void loop() {

  //delay(2000);  // "wait for 2000"
  //  val = !val;
  // then change val;

  boolean buttonPressed = digitalRead(BUTTON_PIN);

  //if (buttonPressed) {
  // do something
  // digitalWrite(LED_PIN, HIGH);
  //}


  boolean value = digitalRead(BUTTON_PIN);
  digitalWrite(LED_PIN, value);
}
