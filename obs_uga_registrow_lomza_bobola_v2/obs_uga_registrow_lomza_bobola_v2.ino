 // Obsłuka registrów
// Organy Lomża
// Autor: Romuald Milewski

int i=0;
const unsigned long delta_time = 4000; // czas po jakim linia zostanie wyłaczona w ms
const unsigned long delta_tremolo_time = 200;
// definiowanie linii wejściowych
#define reg_1 19
#define reg_2 18
#define reg_3 21
#define reg_4 20
#define reg_5 23
#define reg_6 22
#define reg_7 25
#define reg_8 24
#define reg_9 27
#define reg_10 26
#define reg_11 29
#define reg_12 28
#define reg_13 31
#define reg_14 30
#define reg_15 47
#define reg_16 46
#define reg_17 48
#define reg_18 49
#define reg_19 50
#define reg_20 51
#define reg_21 52
#define reg_22 53
// definiowanie linii wyjściowych 
#define line_ON_reg_1 A0
#define line_OFF_reg_1 A1
#define line_ON_reg_2 A2
#define line_OFF_reg_2 A3
#define line_ON_reg_3 A4
#define line_OFF_reg_3 A5
#define line_ON_reg_4 A6
#define line_OFF_reg_4 A7
#define line_ON_reg_5 A8
#define line_OFF_reg_5 A9
#define line_ON_reg_6 A10
#define line_OFF_reg_6 A11
#define line_ON_reg_7 A12
#define line_OFF_reg_7 A13
#define line_ON_reg_8 A14
#define line_OFF_reg_8 A15
#define line_ON_reg_9 2
#define line_OFF_reg_9 3
#define line_ON_reg_10 4
#define line_OFF_reg_10 5
#define line_ON_reg_11 6
#define line_OFF_reg_11 7
#define line_ON_reg_12 8
#define line_OFF_reg_12 9
#define line_ON_reg_13 10
#define line_OFF_reg_13 11
#define line_ON_reg_14 12
#define line_OFF_reg_14 13
#define line_ON_reg_15 14
#define line_OFF_reg_15 15
#define line_ON_reg_16 16
#define line_OFF_reg_16 17
#define line_ON_reg_17 33
#define line_OFF_reg_17 32
#define line_ON_reg_18 35
#define line_OFF_reg_18 34
#define line_ON_reg_19 37
#define line_OFF_reg_19 36
#define line_ON_reg_20 39
#define line_OFF_reg_20  38
#define line_ON_reg_21 41
#define line_OFF_reg_21 40
#define line_ON_reg_22 43
#define line_OFF_reg_22 42

unsigned long line_ON_time_1;
unsigned long line_ON_time_2;
unsigned long line_ON_time_3;
unsigned long line_ON_time_4;
unsigned long line_ON_time_5;
unsigned long line_ON_time_6;
unsigned long line_ON_time_7;
unsigned long line_ON_time_8 = 0;
unsigned long line_ON_time_9;
unsigned long line_ON_time_10;
unsigned long line_ON_time_11;
unsigned long line_ON_time_12;
unsigned long line_ON_time_13;
unsigned long line_ON_time_14;
unsigned long line_ON_time_15;
unsigned long line_ON_time_16;
unsigned long line_ON_time_17;
unsigned long line_ON_time_18;
unsigned long line_ON_time_19;
unsigned long line_ON_time_20;
unsigned long line_ON_time_21;
unsigned long line_ON_time_22;

unsigned long line_OFF_time_1;
unsigned long line_OFF_time_2;
unsigned long line_OFF_time_3;
unsigned long line_OFF_time_4;
unsigned long line_OFF_time_5;
unsigned long line_OFF_time_6;
unsigned long line_OFF_time_7;
unsigned long line_OFF_time_8 = 0;
unsigned long line_OFF_time_9;
unsigned long line_OFF_time_10;
unsigned long line_OFF_time_11;
unsigned long line_OFF_time_12;
unsigned long line_OFF_time_13;
unsigned long line_OFF_time_14;
unsigned long line_OFF_time_15;
unsigned long line_OFF_time_16;
unsigned long line_OFF_time_17;
unsigned long line_OFF_time_18;
unsigned long line_OFF_time_19;
unsigned long line_OFF_time_20;
unsigned long line_OFF_time_21;
unsigned long line_OFF_time_22;

int state_reg_1 = 0;
int state_reg_2 = 0;
int state_reg_3 = 0;
int state_reg_4 = 0;
int state_reg_5 = 0;
int state_reg_6 = 0;
int state_reg_7 = 0;
int state_reg_8 = 0;
int state_reg_9 = 0;
int state_reg_10 = 0;
int state_reg_11 = 0;
int state_reg_12 = 0;
int state_reg_13 = 0;
int state_reg_14 = 0;
int state_reg_15 = 0;
int state_reg_16 = 0;
int state_reg_17 = 0;
int state_reg_18 = 0;
int state_reg_19 = 0;
int state_reg_20 = 0;
int state_reg_21 = 0;
int state_reg_22 = 0;

const int reg_in_pins[22] = {reg_1, reg_2, reg_3, reg_4, reg_5, reg_6, reg_7, reg_8, reg_9, reg_10, reg_11, reg_12, reg_13, reg_14, reg_15, reg_16, reg_17, reg_18, reg_19, reg_20, reg_21,reg_22};
const int line_ON_reg[22] = {line_ON_reg_1, line_ON_reg_2, line_ON_reg_3, line_ON_reg_4, line_ON_reg_5, line_ON_reg_6, line_ON_reg_7, line_ON_reg_8, line_ON_reg_9, line_ON_reg_10, line_ON_reg_11, line_ON_reg_12, line_ON_reg_13, line_ON_reg_14, line_ON_reg_15, line_ON_reg_16, line_ON_reg_17, line_ON_reg_18, line_ON_reg_19, line_ON_reg_20, line_ON_reg_21,line_ON_reg_22};
const int line_OFF_reg[22] = {line_OFF_reg_1, line_OFF_reg_2, line_OFF_reg_3, line_OFF_reg_4, line_OFF_reg_5, line_OFF_reg_6, line_OFF_reg_7, line_OFF_reg_8, line_OFF_reg_9, line_OFF_reg_10, line_OFF_reg_11, line_OFF_reg_12, line_OFF_reg_13, line_OFF_reg_14, line_OFF_reg_15, line_OFF_reg_16, line_OFF_reg_17, line_OFF_reg_18, line_OFF_reg_19, line_OFF_reg_20, line_OFF_reg_21,line_OFF_reg_22};
unsigned long line_ON_time[22] = {line_ON_time_1, line_ON_time_2, line_ON_time_3, line_ON_time_4, line_ON_time_5, line_ON_time_6, line_ON_time_7, line_ON_time_8, line_ON_time_9, line_ON_time_10, line_ON_time_11, line_ON_time_12, line_ON_time_13, line_ON_time_14, line_ON_time_15, line_ON_time_16, line_ON_time_17, line_ON_time_18, line_ON_time_19, line_ON_time_20, line_ON_time_21, line_ON_time_22};
unsigned long line_OFF_time[22] = {line_OFF_time_1, line_OFF_time_2, line_OFF_time_3, line_OFF_time_4, line_OFF_time_5, line_OFF_time_6, line_OFF_time_7, line_OFF_time_8, line_OFF_time_9, line_OFF_time_10, line_OFF_time_11, line_OFF_time_12, line_OFF_time_13, line_OFF_time_14, line_OFF_time_15, line_OFF_time_16, line_OFF_time_17, line_OFF_time_18, line_OFF_time_19, line_OFF_time_20, line_OFF_time_21,line_OFF_time_22};
int state_regs[22] = {state_reg_1, state_reg_2, state_reg_3, state_reg_4, state_reg_5, state_reg_6, state_reg_7, state_reg_8, state_reg_9, state_reg_10, state_reg_11, state_reg_12, state_reg_13, state_reg_14, state_reg_15, state_reg_16, state_reg_17, state_reg_18, state_reg_19, state_reg_20, state_reg_21,state_reg_22};
unsigned long current_time = 0;
int value_reg = 0;
int tremolo = 7; // linia tremolo dlatego że  i=8 dla registru 9 (reg_9)
bool line_state_8 = false; // stan lini tremolo na registrze 9

void setup() {
   Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  

   for( i = 0; i < 22; ++i){
     pinMode(reg_in_pins[i], INPUT); // ustawianie pinów wejściowych
Serial.print("input ");
Serial.print(i);
Serial.println(" ok");
     pinMode(line_ON_reg[i], OUTPUT); // Ustawianie pinów wyściowych ON
     digitalWrite(line_ON_reg[i], LOW);
Serial.print("output ON ");
Serial.print(i);
Serial.println(" ok");
     pinMode(line_OFF_reg[i], OUTPUT); // Ustawianie pinów wyściowych OFF
     digitalWrite(line_OFF_reg[i], LOW);
Serial.print("output OFF "); 
Serial.print(i);
Serial.println(" ok");    
    }
}
void loop() {
// obsługa tremolo na reg_8 

   if (digitalRead(reg_8) == HIGH) {
        if (millis() % 200 < 100) {
        digitalWrite(line_ON_reg_8, HIGH);
        digitalWrite(line_OFF_reg_8, LOW);
        line_state_8 = true;
        } 
        else {
        digitalWrite(line_ON_reg_8, LOW);
        digitalWrite(line_OFF_reg_8, HIGH);
        line_state_8 = false;
        }
   } else
   {
    digitalWrite(line_OFF_reg_8, LOW);
    digitalWrite(line_ON_reg_8, LOW);
   }

// koniec obsługi tremolo

// Tu zaczyna się obsługa pozostałych linii
  
   for(int i = 0; i < 22; ++i){
    value_reg = digitalRead(reg_in_pins[i]);  // odczyt pin wejść i właczenie linii wyjściowej
  if (state_regs[i] != value_reg){
    
  
    if (value_reg == HIGH){   
      Serial.print("Włączenie zasuwy "); 
      Serial.print(i+1);
      Serial.println(" ok");         
     if( i!=tremolo){
      digitalWrite(line_OFF_reg[i], LOW);
    
      digitalWrite(line_ON_reg[i], HIGH);
      line_ON_time[i] = millis();
      
          }
       }
     else{
      Serial.print("Wyłącznie zasuwy ");
      Serial.print(i+1);
      Serial.println(" ok"); 
      if( i!=tremolo){
      digitalWrite(line_ON_reg[i], LOW);
      digitalWrite(line_OFF_reg[i], HIGH);
      line_OFF_time[i] = millis();
      
      }
     }
   }
 state_regs[i] = value_reg;  
  } 

lineOFF_after_time(); // wyłacza linię po zadanym casie   
}


// funkcja wyłaczajaca linie ON lub OFF po zadanym czasie
void lineOFF_after_time(){
  current_time = millis();
  for( i = 0; i < 22; ++i){
                            // // && i != 7 dla pominięcia wyłaczenia ON 8 zasuwy
    if(current_time > (line_ON_time[i] + delta_time)&& i != 7 && i != 8 && i != 14 && i != 15 && i != 9) {
      digitalWrite(line_ON_reg[i], LOW);
    }
                           // && i != 7 dla pominięcia wyłaczenia OFF 8 zasuwy
     if(current_time > (line_OFF_time[i] + delta_time)&& i != 7 && i != 8 && i != 14 && i != 15 && i != 9) {
      digitalWrite(line_OFF_reg[i], LOW);
    }
  }
     
}
