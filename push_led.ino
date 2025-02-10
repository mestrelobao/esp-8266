#define BUTTON_PIN 4
#define DEBOUNCE_TIME 50

int lastSteadyState = LOW;
int lastFlickerableState = LOW;
int currentState;
unsigned long lastDebounceTime = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(BUTTON_PIN, INPUT_PULLUP);
pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
currentState = digitalRead(BUTTON_PIN);
if (currentState != lastFlickerableState) {

lastDebounceTime = millis();
lastFlickerableState = currentState;
}

if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
if(lastSteadyState == HIGH && currentState == LOW)
digitalWrite(LED_BUILTIN, HIGH);
else if (lastSteadyState == LOW && currentState == HIGH)
digitalWrite(LED_BUILTIN, LOW); 
lastSteadyState = currentState;
}
}
