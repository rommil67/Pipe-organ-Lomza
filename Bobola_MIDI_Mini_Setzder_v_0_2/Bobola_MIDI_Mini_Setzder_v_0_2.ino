
// MIDI_Mini_Setzer_v.0.2


#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();


const int buttonOffPins[] = {30, 31, 28, 29,  26, 27,  24, 25,   A11,    41, 38, 39, 36, 37, 34, 35,      A5, A4, A7, A6, A9, A8      }; //{2, 3, 4, 5, 6, 7, 8, 9};
const int buttonOnPins[] =  { 48, 49, 50, 51,  A2, A3, A0, A1,    32,   46, 47, 44,  45,  42, 43, 40,   A10, A13, A12, A15, A14, 33      }; //{10, 11, 12, 13, 14, 15, 16, 17}; // Przyciski Off (górne)
//włącza 8 diod
const int ledPins[] = {17, 16, 19, 18, 21, 20, 23, 22,   8,    3, 2, 5, 4, 7, 6,    9, 14, 15, 12, 13, 10, 11 };
int combinationPins[6] = {0};
// Led WK
int combinationLedPins[6] = {0};
//piston Set
const int pistonSetPin = 52;
unsigned long millisStorage = 0;

bool ledState[22] = {false}; // Tablica do przechowywania stanu diod
bool buttonOffState[22] = {false}; // Tablica do przechowywania stanu przycisków
bool buttonOnState[22] = {false}; // Tablica do przechowywania stanu przycisków
bool combinationLedState[6] = {false}; // Tablica do przechowywania stanu diod WK
bool combinationButtonState[6] = {false}; //Tablica do przechowywania stanu p
bool pistonSetState = false;
bool freeComb[6][22] = {false}; // // Tablica dwuwymiarowa  do przechowywania stanu WK

const byte midiChannel = 1; // Domyślny numer kanału MIDI (od 1 do 16)

void setup() {
    // Connect the handleNoteOn function to the library,
    // so it is called upon reception of a NoteOn.
    MIDI.setHandleNoteOn(handleNoteOn);  // Put only the name of the function

    // Do the same for NoteOffs
    MIDI.setHandleNoteOff(handleNoteOff);

    // Initiate MIDI communications, listen to all channels
    MIDI.begin(MIDI_CHANNEL_OMNI);

for (int i = 0; i < 22; i++) {
  pinMode(buttonOffPins[i], INPUT_PULLUP);
  pinMode(buttonOnPins[i], INPUT_PULLUP);
  pinMode(ledPins[i], OUTPUT);
  digitalWrite(ledPins[i], LOW);

}

  for (int i = 0; i < 6; i++) {
    combinationPins[i] = 0;
    combinationLedPins[i] = 0;
    
  }
  pinMode(pistonSetPin, INPUT_PULLUP);
  //digitalWrite(pistonSetPin, HIGH);
//registerLedOff();
//freeCombLedOff();
//delay(2000);
}

void loop() {
  // Call MIDI.read the fastest you can for real-time performance.
    MIDI.read();

  for (int i = 0; i < 22; i++) {
    buttonOnState[i] = digitalRead(buttonOnPins[i]); // Odczytaj stan przycisku włączania
    buttonOffState[i] = digitalRead(buttonOffPins[i]); // Odczytaj stan przycisku wyłączania

    if (buttonOnState[i] == LOW && !ledState[i]) { // Jeśli przycisk włączania jest wciśnięty i dioda jest wyłączona
      digitalWrite(ledPins[i], HIGH); // Włącz diodę
      ledState[i] = true; // Zapisz stan diody jako włączony
     MIDI.sendNoteOn(i+36, 127, 1);
    }

    if (buttonOffState[i] == LOW && ledState[i]) { // Jeśli przycisk wyłączania jest wciśnięty i dioda jest włączona
      digitalWrite(ledPins[i], LOW); // Wyłącz diodę
      ledState[i] = false; // Zapisz stan diody jako wyłączony
     MIDI.sendNoteOff(i+36, 0, 1);
    }
  }

  pistonSetState = digitalRead(pistonSetPin);
  if (pistonSetState == LOW && millisStorage < millis()+500){
    millisStorage = millis();
   setFunction();
  }
 
pistonControls();

}


void pistonControls(){
   
 if (combinationPins[0] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 1");
 }  

 if (combinationPins[1] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 2");
 }  

  if (combinationPins[2] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 3");   
 }  

  if (combinationPins[3] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 3");   
 }  

  if (combinationPins[4] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 3");   
 }  

  if (combinationPins[5] == 1 && millisStorage < millis()+100){
   millisStorage = millis();
   
   readFreeComb();
   //Serial.println("Comb 3");   
 }  
}

void setFunction() {
 
   for (int j = 0; j < 3; j++) {
    if(digitalRead(combinationPins[j]) == LOW){
     for (int i = 0; i < 22; i++) {
     freeComb[j][i] = ledState[i];
      }        
    }
  }
}

void readFreeComb() {
 
   for (int j = 0; j < 6; j++) {
    if (combinationPins[j] == 1){
     
     
     for (int i = 0; i < 22; i++) {
    if (freeComb[j][i] == true  && !ledState[i]){
       digitalWrite(ledPins[i], LOW); // Włącz diodę
       ledState[i] = true; // Zapisz stan diody jako włączony
       MIDI.sendNoteOn(i+36, 127, 1);
       }
    if (freeComb[j][i] == false && ledState[i]){
       digitalWrite(ledPins[i], HIGH); // Wyłącz diodę
       ledState[i] = false; // Zapisz stan diody jako wyłączony
       MIDI.sendNoteOff(i+36, 0, 1);
      }      
    }
   }
  }
}



void freeCombLedOff(){
  for(int n = 0; n < 6; n++){
       combinationLedPins[n] = 0;
      }
}

void handleNoteOn(byte channel, byte pitch, byte velocity)
{
if (channel==1){
   int i = pitch - 36;
   digitalWrite(ledPins[i], HIGH); // Włącz diodę
   ledState[i] = true; // Zapisz stan diody jako włączony
  }  
  if (channel==9){ // odbiór komunikatu ABCPda
   int i = pitch - 36;
   combinationPins[i] = 1;
   //digitalWrite(ledPins[i], HIGH); // Włącz diodę
   //ledState[i] = true; // Zapisz stan diody jako włączony
  } 
    // Do whatever you want when a note is pressed.

    // Try to keep your callbacks short (no delays ect)
    // otherwise it would slow down the loop() and have a bad impact
    // on real-time performance.
}

void handleNoteOff(byte channel, byte pitch, byte velocity)
{
  if (channel==1){
     int i = pitch - 36;
     digitalWrite(ledPins[i], LOW); // Wyłącz diodę
     ledState[i] = false; // Zapisz stan diody jako wyłączony
    }
  if (channel==9){ // odbiór komunikatu ABCPda
   int i = pitch - 36;
   combinationPins[i] = 0;
   //digitalWrite(ledPins[i], HIGH); // Włącz diodę
   //ledState[i] = true; // Zapisz stan diody jako włączony
  } 
    // Do something when the note is released.
    // Note that NoteOn messages with 0 velocity are interpreted as NoteOffs.
}
