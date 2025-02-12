int button = 0;

int led = 16;

int status = LOW;



void setup(){

pinMode(led, OUTPUT);

pinMode(button, INPUT_PULLUP); // setting the internal Pull up resistor of the button, that is HIGH

}



void loop(){

// Initially the button is unpressed and is HIGH (pull up) and is not equal to LOW therefore

// the inversion will be bypassed and the LED status will be LOW

//If the button is pressed its status will become LOW that means (a) status = (b) status

// Therefore status=!status will inverse and the LED will Light (HIGH)



if (digitalRead(button) == LOW) { 

status = !status;

digitalWrite(led, status);

} while(digitalRead(button) == LOW);

delay(50); // keep a small delay

}
