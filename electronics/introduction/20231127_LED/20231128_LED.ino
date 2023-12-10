#define LED 13 // define the constant "name" for your pin 
#define BUTTON 8

boolean val = HIGH; // HIGH = 1 = ON
boolean val = digitalRead (BUTTON);


void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(2000); // "wait for 2000"
  val = !val; // then change val
 

}
