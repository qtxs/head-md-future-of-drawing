#define POWER_PIN 7
#define SIGNAL_PIN A0
#define LED_PIN_RED 13
#define LED_PIN_BLUE 12

float col;

int value = 0;  // variable to store the sensor value

void setup() {
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);  // configure D7 pin as an OUTPUT
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
  digitalWrite(POWER_PIN, LOW);  // turn the sensor OFF
}

void loop() {

  digitalWrite(POWER_PIN, HIGH);   // turn the sensor ON
  delay(100);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN);  // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);    // turn the sensor OFF



  // if (value > 200) {
  //   digitalWrite(LED_PIN_RED, HIGH);
  // } else {
  //   digitalWrite(LED_PIN_RED, LOW);
  // }

  //  if (value > 400) {
  //     digitalWrite(LED_PIN_BLUE, HIGH);
  //   } else {
  //     digitalWrite(LED_PIN_BLUE, LOW);
  //   }


  int color = map(value, 0, 400, 0, 100);



  digitalWrite(LED_PIN_RED, color);
  delay(10);
 // digitalWrite(LED_PIN_BLUE, !color);


  //Serial.println(value);
  Serial.println(color);

  delay(1000);



  //allumer les led differents suivant la valeur
}