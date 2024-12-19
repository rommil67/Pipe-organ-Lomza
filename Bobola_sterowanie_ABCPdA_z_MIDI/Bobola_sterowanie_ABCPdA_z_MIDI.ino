/* Sterowanie kombinacjami w organach w kościele św. A. Boboli w Łomży
 *   Organ - Bobola Lomza
 *  Author: Romuald Milewski
 *  
 */
 int midi_channel = 0x98; 
 int off_midi_channel = 0x88;
 int przycisk_A = A4;
 int przycisk_B = 2;
 int przycisk_C = A5;
 int przycisk_Pleno = 3;
 int przycisk_d = 9;
 int przycisk_anuluj = 10;
 int LED_A = 4;
 int LED_B = 5;
 int LED_C = 6;
 int LED_Pleno = 7;
 int LED_d = 8;

 
 byte stanpedfreereg = 0;
 byte stan_przycisku_8 = 0;
 
void setup() {
  Serial.begin(31250);
  // ustawianie wejśc i wyjśc

pinMode(przycisk_A, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
pinMode(przycisk_B, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
pinMode(przycisk_C, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
pinMode(przycisk_Pleno, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
pinMode(przycisk_d, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
pinMode(przycisk_anuluj, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
// definiowanie wyjść LED i podciąganie ich do HIGH
pinMode(LED_A, OUTPUT);
digitalWrite(LED_A, HIGH);
pinMode(LED_B, OUTPUT);
digitalWrite(LED_B, HIGH);
pinMode(LED_C, OUTPUT);
digitalWrite(LED_C, HIGH);
pinMode(LED_Pleno, OUTPUT);
digitalWrite(LED_Pleno, HIGH);
pinMode(LED_d, OUTPUT);
digitalWrite(LED_d, HIGH);
// definiowanie wyjść Line i ustawianie ich staanu na stan niski - LOW

}

void loop() {
  while (digitalRead(przycisk_A) == HIGH && digitalRead(przycisk_B) == HIGH && digitalRead(przycisk_C) == HIGH && digitalRead(przycisk_Pleno) == HIGH && digitalRead(przycisk_d) && digitalRead(przycisk_anuluj) == HIGH) { 
    // Nie robi nic - czeka na naciśniecie przycisku
  }
  
// włączenie przycisku na pinie przycisk_A 
 if (digitalRead(przycisk_A) == LOW){
    

    digitalWrite (LED_A, LOW);
    digitalWrite (LED_B, HIGH);
    digitalWrite (LED_C, HIGH);
    digitalWrite (LED_Pleno, HIGH);
    digitalWrite (LED_d, HIGH);

    noteOn(midi_channel, 36, 0x45);
    noteOn(midi_channel, 37, 0x00);
    noteOn(midi_channel, 38, 0x00);
    noteOn(midi_channel, 39, 0x00);
    noteOn(midi_channel, 40, 0x00);
    noteOn(midi_channel, 41, 0x00);
    
    while (digitalRead(przycisk_A) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
    }
    
    delay(50);
    
  }
//******************************************************************


// włączenie przycisku na pinie przycisk_B
 if (digitalRead(przycisk_B) == LOW){
   
    digitalWrite (LED_A, HIGH);
    digitalWrite (LED_B, LOW);
    digitalWrite (LED_C, HIGH);
    digitalWrite (LED_Pleno, HIGH);
    digitalWrite (LED_d, HIGH);

    noteOn(midi_channel, 36, 0x00);
    noteOn(midi_channel, 37, 0x45);
    noteOn(midi_channel, 38, 0x00);
    noteOn(midi_channel, 39, 0x00);
    noteOn(midi_channel, 40, 0x00);
    noteOn(midi_channel, 41, 0x00);

    while (digitalRead(przycisk_B) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
//****************************************************************

    
// włączenie przycisku na pinie C 
  if (digitalRead(przycisk_C) == LOW){
    

    digitalWrite (LED_A, HIGH);
    digitalWrite (LED_B, HIGH);
    digitalWrite (LED_C, LOW);
    digitalWrite (LED_Pleno, HIGH);
    digitalWrite (LED_d, HIGH);

    noteOn(midi_channel, 36, 0x00);
    noteOn(midi_channel, 37, 0x00);
    noteOn(midi_channel, 38, 0x45);
    noteOn(midi_channel, 39, 0x00);
    noteOn(midi_channel, 40, 0x00);
    noteOn(midi_channel, 41, 0x00);

    while (digitalRead(przycisk_C) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
//******************************************************************
    
 // włączenie przycisku na pinie Pleno 
  if (digitalRead(przycisk_Pleno) == LOW){
    
    digitalWrite (LED_A, HIGH);
    digitalWrite (LED_B, HIGH);
    digitalWrite (LED_C, HIGH);
    digitalWrite (LED_Pleno, LOW);
    digitalWrite (LED_d, HIGH);

    noteOn(midi_channel, 36, 0x00);
    noteOn(midi_channel, 37, 0x00);
    noteOn(midi_channel, 38, 0x00);
    noteOn(midi_channel, 39, 0x45);
    noteOn(midi_channel, 40, 0x00);
    noteOn(midi_channel, 41, 0x00);

    while (digitalRead(przycisk_Pleno) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  
 //**************************************************************    

   // włączenie przycisku na pinie przycisk_d ( d - ON )
  if (digitalRead(przycisk_d) == LOW) {
    
    
    

    digitalWrite (LED_A, HIGH);
    digitalWrite (LED_B, HIGH);
    digitalWrite (LED_C, HIGH);
    digitalWrite (LED_Pleno, HIGH);
    digitalWrite (LED_d, LOW);

    noteOn(midi_channel, 36, 0x00);
    noteOn(midi_channel, 37, 0x00);
    noteOn(midi_channel, 38, 0x00);
    noteOn(midi_channel, 39, 0x00);
    noteOn(midi_channel, 40, 0x45);
    noteOn(midi_channel, 41, 0x00);

    while (digitalRead(przycisk_d) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50); 
    
    }  
//************************************************************ 

 
 
//************************************************************

  // włączenie przycisku na pinie przycisk_anuluj
   
  if (digitalRead(przycisk_anuluj) == LOW){
   

    digitalWrite (LED_A, HIGH);
    digitalWrite (LED_B, HIGH);
    digitalWrite (LED_C, HIGH);
    digitalWrite (LED_Pleno, HIGH);
    digitalWrite (LED_d, HIGH);

    noteOn(midi_channel, 36, 0x00);
    noteOn(midi_channel, 37, 0x00);
    noteOn(midi_channel, 38, 0x00);
    noteOn(midi_channel, 39, 0x00);
    noteOn(midi_channel, 40, 0x00);
    noteOn(midi_channel, 41, 0x45);

    while (digitalRead(przycisk_anuluj) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50);
    }  

 //koniec
}   

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

      
