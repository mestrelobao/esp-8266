void setup()

{
    //Set up serial output with standard MIDI baud rate
    Serial.begin(31250);
    byte noteOnStatus=0xFA;  
    Serial.write(noteOnStatus);
}

void loop()

{
 
}
