void setup()

{

    //Set up serial output with standard MIDI baud rate

    Serial.begin(31250);

    

}



void loop()

{

    //Play a G7M chord

  
  playMIDINote(1, 55, 100);
  playMIDINote(1, 66, 100);
  playMIDINote(1, 71, 100);
  playMIDINote(1, 74, 100);

        //Hold note for 60 ms (delay() used for simplicity)

        delay(60);

        

        //Turn chord off (velocity = 0)

  playMIDINote(1, 55, 0);
  playMIDINote(1, 66, 0);
  playMIDINote(1, 71, 0);
  playMIDINote(1, 74, 0);

        //Pause for 60 ms

        delay(60);
  
 //Play a D7M chord
  
  playMIDINote(1, 62, 100);
  playMIDINote(1, 69, 100);
  playMIDINote(1, 73, 100);
  playMIDINote(1, 77, 100);

        //Hold note for 60 ms (delay() used for simplicity)

        delay(60);

        

        //Turn chord off (velocity = 0)

  playMIDINote(1, 62, 0);
  playMIDINote(1, 69, 0);
  playMIDINote(1, 73, 0);
  playMIDINote(1, 79, 0);

        //Pause for 60 ms

        delay(60);
}



void playMIDINote(byte channel, byte note, byte velocity)

{

    //MIDI channels 1-16 are really 0-15

    byte noteOnStatus=0x90 + (channel-1);  

    

    //Send notes to MIDI output:

    Serial.write(noteOnStatus);

    Serial.write(note);

    Serial.write(velocity);

}
