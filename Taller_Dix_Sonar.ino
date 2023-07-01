#include <NewPing.h>
#include <toneAC.h>

#define TRIGGER_PIN_1 2
#define ECHO_PIN_1 3
#define TRIGGER_PIN_2 4
#define ECHO_PIN_2 5
#define TRIGGER_PIN_3 6
#define ECHO_PIN_3 7
#define BUTTON_PIN_1 11
#define BUTTON_PIN_2 12
#define BUTTON_PIN_3 13


//int scale[] = {261, 293, 329, 349, 392, 440, 493, 523};

int DO_3=130;
int RE_3=146;
int MI_3=164;
int FA_3=174;
int SOL_3=196;
int LA_3=220;
int SI_3=246;
int DO_4=261;
int RE_4=293;
int MI_4=329;
int FA_4=349;
int SOL_4=392;
int LA_4=440;
int SI_4=493;
int DO_5=523;
int RE_5=587;
int MI_5=659;
int FA_5=698;
int SOL_5=783;
int LA_5=880;
int SI_5=987;
int DO_6=1046;



int tiempo=100;

//int scale[] = {DO_4, RE_4, MI_4, FA_4, SOL_4, LA_4, SI_4, DO_5};
//int scale[] = {261, 293, 329, 349, 392, 440, 493, 523};

// 261:C4=DO4  293:D4=RE4 329:E4=MI4 349:F4=FA4 392:G4=SOL4 440:LA=A4 493:B4=SI 523:C5=D0 

unsigned long d1,d2;

NewPing sonar1(2, 3);
NewPing sonar2(4, 5);
NewPing sonar3(6, 7);

void setup() {
  Serial.begin(9600);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  
}

void loop() {

  int duration1 = 0;
  int duration2 = 0;
  int duration3 = 0;
  d2=millis();
  
  if (digitalRead(11) == LOW) {
    duration1 = sonar1.ping_cm();
    if (duration1 >= 5 && duration1 <= 85) {
      int note = getNoteForDistance1(duration1);
      if (note != -1) {
        playTone(0, 100);
      }
    }
  }

  if (digitalRead(12) == LOW) {
    duration2 = sonar2.ping_cm();
    if (duration2 >= 5 && duration2 <= 85) {
      int note = getNoteForDistance2(duration2);
      if (note != -1) {
        playTone(0, 100);
      }
    }
  }

  if (digitalRead(13) == LOW) {
    duration3 = sonar3.ping_cm();
    if (duration3 >= 5 && duration3 <= 85) {
      int note = getNoteForDistance3(duration3);
      if (note != -1) {
        playTone(0, 100);
      }
    }
  }

}

int getNoteForDistance1(int distance) {
  if (distance > 85){
    noToneAC();
  }
  if (distance >= 5 && distance < 15) {
    toneAC(DO_3, 1000);
    delay(tiempo);
    noToneAC();
    return 0;
  } 
  else if (distance >= 15 && distance < 25) {
    toneAC(RE_3, 1000);
    delay(tiempo);
    noToneAC();
    return 1;
  } 
  else 
    if (distance >= 25 && distance < 35) {
    toneAC(MI_3, 1000);
    delay(tiempo);
    noToneAC();
    return 2;
  } else 
    if (distance >= 35 && distance < 45) {
    toneAC(FA_3, 1000);
    delay(tiempo);
    noToneAC();
    return 3;
  } 
  else 
    if (distance >= 45 && distance < 55) {
    toneAC(SOL_3, 1000);
    delay(tiempo);
    noToneAC();
    return 4;
  } 
  else 
    if (distance >= 55 && distance <= 65) {
    toneAC(LA_3, 1000);
    delay(tiempo);
    noToneAC();
    return 5;
  }
  else 
    if (distance >= 65 && distance <= 75) {
    toneAC(SI_3, 1000);
    delay(tiempo);
    noToneAC();
    return 6;
  }
  else
   if (distance >= 75 && distance <= 85) {
    toneAC(DO_4, 1000);
    delay(tiempo);
    noToneAC();
    return 7;
  } 
  else {
    return -1;
  }
}


int getNoteForDistance2(int distance) {
  if (distance > 85){
    noToneAC();
  }
  if (distance >= 5 && distance < 15) {
    toneAC(DO_4, 1000);
    delay(tiempo);
    noToneAC();
    return 0;
  } 
  else if (distance >= 15 && distance < 25) {
    toneAC(RE_4, 1000);
    delay(tiempo);
    noToneAC();
    return 1;
  } 
  else 
    if (distance >= 25 && distance < 35) {
    toneAC(MI_4, 1000);
    delay(tiempo);
    noToneAC();
    return 2;
  } else 
    if (distance >= 35 && distance < 45) {
    toneAC(FA_4, 1000);
    delay(tiempo);
    noToneAC();
    return 3;
  } 
  else 
    if (distance >= 45 && distance < 55) {
    toneAC(SOL_4, 1000);
    delay(tiempo);
    noToneAC();
    return 4;
  } 
  else 
    if (distance >= 55 && distance <= 65) {
    toneAC(LA_4, 1000);
    delay(tiempo);
    noToneAC();
    return 5;
  }
  else 
    if (distance >= 65 && distance <= 75) {
    toneAC(SI_4, 1000);
    delay(tiempo);
    noToneAC();
    return 6;
  }
  else
   if (distance >= 75 && distance <= 85) {
    toneAC(DO_5, 1000);
    delay(tiempo);
    noToneAC();
    return 7;
  } 
  else {
    return -1;
  }
}

int getNoteForDistance3(int distance) {
  if (distance > 85){
    noToneAC();
  }
  if (distance >= 5 && distance < 15) {
    toneAC(DO_5, 1000);
    delay(tiempo);
    noToneAC();
    return 0;
  } 
  else if (distance >= 15 && distance < 25) {
    toneAC(RE_5, 1000);
    delay(tiempo);
    noToneAC();
    return 1;
  } 
  else 
    if (distance >= 25 && distance < 35) {
    toneAC(MI_5, 1000);
    delay(tiempo);
    noToneAC();
    return 2;
  } else 
    if (distance >= 35 && distance < 45) {
    toneAC(FA_5, 1000);
    delay(tiempo);
    noToneAC();
    return 3;
  } 
  else 
    if (distance >= 45 && distance < 55) {
    toneAC(SOL_5, 1000);
    delay(tiempo);
    noToneAC();
    return 4;
  } 
  else 
    if (distance >= 55 && distance <= 65) {
    toneAC(LA_5, 1000);
    delay(tiempo);
    noToneAC();
    return 5;
  }
  else 
    if (distance >= 65 && distance <= 75) {
    toneAC(SI_5, 1000);
    delay(tiempo);
    noToneAC();
    return 6;
  }
  else
   if (distance >= 75 && distance <= 85) {
    toneAC(DO_6, 1000);
    delay(tiempo);
    noToneAC();
    return 7;
  } 
  else {
    return -1;
  }
}

void playTone(int note, int duration) { // Reproducir el tono con la frecuencia y duración especificadas
  
  d2=millis();
  if(d2-d1>=100)
  {    
    toneAC(note, duration);
   } 
  //toneAC(note, duration); 
  //delay(100);
  noToneAC();
}