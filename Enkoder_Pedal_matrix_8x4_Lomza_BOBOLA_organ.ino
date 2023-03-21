#include <Control_Surface.h>

USBMIDI_Interface midi;
//HardwareSerialMIDI_Interface serialmidi = {Serial, MIDI_BAUD};
//HairlessMIDI_Interface midi;
// The note numbers corresponding to the buttons in the matrix
const AddressMatrix<8, 4> addresses = {{
  { 36, 44, 52, 60 },
  { 37, 45, 53, 61 },
  { 38, 46, 54, 62 },
  { 39, 47, 55, 63 },
  { 40, 48, 56, 64 },
  { 41, 49, 57, 65 },
  { 42, 50, 58, 66 },
  { 43, 51, 59, 67 },
  
}};

NoteButtonMatrix<8, 4> buttonmatrix = {
 
{ 4, 5, 6, 7, 8, 9, 10, 11}, // row pins
{2, 3, 12, 13},// column pins
addresses, // address matrix
CHANNEL_1, // channel and cable number
};


void setup() {
Control_Surface.begin();
}

void loop() {
Control_Surface.loop();
}
