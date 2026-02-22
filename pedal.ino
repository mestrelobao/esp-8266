#include <ezButton.h>

ezButton botao1(0); //pin D3
ezButton botao2(5); //pin D1
ezButton botao3(12); //pin D6
ezButton botao4(14); //pin D5
ezButton botao5(13); //pin D7
ezButton botao6(10); //pin SD3
void setup() {
//  Serial.begin(9600);
Serial.begin(31250);
botao1.setDebounceTime(20);
botao2.setDebounceTime(20);
botao3.setDebounceTime(20);
botao4.setDebounceTime(20);
botao5.setDebounceTime(20);
botao6.setDebounceTime(20);
}

void loop() {
  botao1.loop(); // MUST call the loop() function first
  botao2.loop();
  botao3.loop();
  botao4.loop();  
  botao5.loop();
  botao6.loop();
 
 if(botao1.isPressed())
//Serial.println(F("botão 1 (D3) pressionado!"));
A7M();
 // if(botao1.isReleased())
 //allsoundoff(1, 120, 0);
 
  if(botao2.isPressed()) 
Bm7();
  
if(botao4.isPressed())
Csustenido_m7();

if(botao5.isPressed()) //mute
 allsoundoff(1, 120, 0);

if(botao6.isPressed()) //mute
allsoundoff(1, 120, 0);
//Serial.println(F("botão 6 (SD3) pressionado!"));


}
void A7M(){
 allsoundoff(1, 120, 0);
 playMIDINote(1, 45, 100);
 playMIDINote(1, 56, 100);
 playMIDINote(1, 61, 100);
 playMIDINote(1, 64, 100);  
}
void G7M(){
 allsoundoff(1, 120, 0);
 playMIDINote(1, 43, 100);
 playMIDINote(1, 54, 100);
 playMIDINote(1, 59, 100);
 playMIDINote(1, 62, 100);  
}
void Bm7(){
 allsoundoff(1, 120, 0);
 playMIDINote(1, 47, 100);
 playMIDINote(1, 57, 100);
 playMIDINote(1, 62, 100);
 playMIDINote(1, 66, 100);  
}
void Csustenido_m7(){
 allsoundoff(1, 120, 0);
 playMIDINote(1, 49, 100);
 playMIDINote(1, 59, 100);
 playMIDINote(1, 64, 100);
 playMIDINote(1, 68, 100);  
}
void playMIDINote(byte channel, byte note, byte velocity) {
byte noteOnStatus=0x90 + (channel-1);  

    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}

void allsoundoff(byte channel, byte note, byte velocity) {
byte noteOnStatus=0xB0 + (channel-1);  
    Serial.write(noteOnStatus);
    Serial.write(note);
    Serial.write(velocity);
}
