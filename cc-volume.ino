void setup()

{
    //Set up serial output with standard MIDI baud rate

 Serial.begin(31250);
//5B reverb
 byte noteOnStatus=0xB0 + 0;  

    Serial.write(noteOnStatus);

    Serial.write(7);

    Serial.write(10);
  
  }

void loop()

{
 
}
