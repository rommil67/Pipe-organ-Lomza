/* Sterowanie kombinacjami w organach w kościele św. A. Boboli w Łomży
 *   Organ - Bobola Lomza
 *  Author: Romuald Milewski
 *  
 */
 int midi_channel = 0x98; 
 int off_midi_channel = 0x88;
 int przycisk_A = 2;
 int przycisk_B = 3;
 int przycisk_C = 4;
 int przycisk_Pleno = 5;
 int przycisk_d = 6;
 int przycisk_anuluj = 7;
 int LED_A = 8;
 int LED_B = 9;
 int LED_C = 10;
 int LED_Pleno = 11;
 int LED_d = 12;
 int Line_A = 13;
 int Line_B = A0;
 int Line_C = A1;
 int Line_Pleno = A2;
 int Line_d = A3;
 int Line_A_ped = A4;
 int Line_B_ped = A5;
 int Line_C_ped = 0;
 int Line_Pleno_ped = 1;

 int stan_Line_d = 0;
 int stan_LED_d = 0;
 
 byte stanpedfreereg = 0;
 byte stan_przycisku_8 =0;
 
void setup() {
  Serial.begin(31250);
  // ustawianie wejśc i wyjśc
  for (int a=2; a<8; a++)
{
pinMode(a, INPUT_PULLUP); // ustawia piny 2-9 jako wejścia i podciaga do High
}

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
pinMode(Line_A, OUTPUT);
digitalWrite(Line_A, LOW);
pinMode(Line_B, OUTPUT);
digitalWrite(Line_B, LOW);
pinMode(Line_C, OUTPUT);
digitalWrite(Line_C, LOW);
pinMode(Line_Pleno, OUTPUT);
digitalWrite(Line_Pleno, LOW);
pinMode(Line_d, OUTPUT);
digitalWrite(Line_d, LOW);
pinMode(Line_A_ped, OUTPUT);
digitalWrite(Line_A_ped, LOW);
pinMode(Line_B_ped, OUTPUT);
digitalWrite(Line_B_ped, LOW);
pinMode(Line_C_ped, OUTPUT);
digitalWrite(Line_C_ped, LOW);
pinMode(Line_Pleno_ped, OUTPUT);
digitalWrite(Line_Pleno_ped, LOW);
  
}

void loop() {
  while (digitalRead(przycisk_A) == HIGH && digitalRead(przycisk_B) == HIGH && digitalRead(przycisk_C) == HIGH && digitalRead(przycisk_Pleno) == HIGH && digitalRead(przycisk_d) && digitalRead(przycisk_anuluj) == HIGH) { 
    // Nie robi nic - czeka na naciśniecie przycisku
  }
  
// włączenie przycisku na pinie przycisk_A 
 if (digitalRead(przycisk_A) == LOW){
    digitalWrite (Line_A, HIGH); // A - ON
    digitalWrite (Line_A_ped, HIGH);
    digitalWrite (Line_B, LOW);
    digitalWrite (Line_B_ped, LOW);
    digitalWrite ( Line_C, LOW);
    digitalWrite ( Line_C_ped, LOW);
    digitalWrite ( Line_Pleno, LOW);
    digitalWrite ( Line_Pleno_ped, LOW);
    digitalWrite ( Line_d, LOW);

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
     digitalWrite (Line_A, LOW); // A - ON
    digitalWrite (Line_A_ped, LOW);
    digitalWrite (Line_B, HIGH);
    digitalWrite (Line_B_ped, HIGH);
    digitalWrite ( Line_C, LOW);
    digitalWrite ( Line_C_ped, LOW);
    digitalWrite ( Line_Pleno, LOW);
    digitalWrite ( Line_Pleno_ped, LOW);
    digitalWrite ( Line_d, LOW);

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
      digitalWrite (Line_A, LOW); // A - ON
    digitalWrite (Line_A_ped, LOW);
    digitalWrite (Line_B, LOW);
    digitalWrite (Line_B_ped, LOW);
    digitalWrite ( Line_C, HIGH);
    digitalWrite ( Line_C_ped, HIGH);
    digitalWrite ( Line_Pleno, LOW);
    digitalWrite ( Line_Pleno_ped, LOW);
    digitalWrite ( Line_d, LOW);

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
     digitalWrite (Line_A, LOW); // A - ON
    digitalWrite (Line_A_ped, LOW);
    digitalWrite (Line_B, LOW);
    digitalWrite (Line_B_ped, LOW);
    digitalWrite ( Line_C, LOW);
    digitalWrite ( Line_C_ped, LOW);
    digitalWrite ( Line_Pleno, HIGH);
    digitalWrite ( Line_Pleno_ped, HIGH);
    digitalWrite ( Line_d, LOW);

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
  if (digitalRead(przycisk_d) == LOW && stan_Line_d == LOW){
    //digitalWrite (Line_A, LOW); // A - ON
    digitalWrite (Line_A_ped, LOW);
    //digitalWrite (Line_B, LOW);
    digitalWrite (Line_B_ped, LOW);
    //digitalWrite ( Line_C, LOW);
    digitalWrite ( Line_C_ped, LOW);
    //digitalWrite ( Line_Pleno, LOW);
    digitalWrite ( Line_Pleno_ped, LOW);
    
    digitalWrite ( Line_d, HIGH);

    //digitalWrite (LED_A, HIGH);
    //digitalWrite (LED_B, HIGH);
    //digitalWrite (LED_C, HIGH);
    //digitalWrite (LED_Pleno, LOW);
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
    stan_Line_d = HIGH;
    }  
//************************************************************ 

 
   // wyączenie przycisku na pinie przycisk_d (d - OFF)
  if (digitalRead(przycisk_d) == LOW && stan_Line_d == HIGH){
   //digitalWrite (Line_A, LOW); // A - ON
    digitalWrite (Line_A_ped, digitalRead(Line_A));
    //digitalWrite (Line_B, LOW);
    digitalWrite (Line_B_ped, digitalRead(Line_B));
    //digitalWrite ( Line_C, LOW);
    digitalWrite ( Line_C_ped, digitalRead(Line_C));
    //digitalWrite ( Line_Pleno, LOW);
    digitalWrite ( Line_Pleno_ped, digitalRead(Line_Pleno));
    
    digitalWrite ( Line_d, LOW); 
    
    //digitalWrite (LED_A, HIGH);
    //digitalWrite (LED_B, HIGH);
    //digitalWrite (LED_C, HIGH);
    //digitalWrite (LED_Pleno, LOW);
    digitalWrite (LED_d, HIGH); // gaszenie lampki d stanem wysokim
    while (digitalRead(przycisk_d) == LOW){
      // czeka aż puśćimy prycisk
      delay(10);
   }
    
    delay(50); 
    stan_Line_d = LOW;
    }  
//************************************************************

  // włączenie przycisku na pinie przycisk_anuluj
   
  if (digitalRead(przycisk_anuluj) == LOW){
   digitalWrite (Line_A, LOW); // 
   digitalWrite (Line_B, LOW);
   digitalWrite ( Line_C, LOW);
   digitalWrite ( Line_Pleno, LOW);
   digitalWrite ( Line_d, LOW);

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

      