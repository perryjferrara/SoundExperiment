#include <Arduino.h>
#define BUZZ_PASSIVE_PIN 8
#include "pitches.h"

/*

  Melody

  Plays a melody

  circuit:

  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010

  modified 30 Aug 2011

  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/Tone

*/

int input;

// notes in the melody:
int melody1[] = {

  NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_A4, NOTE_B4, NOTE_A4,
  NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, 0,
  NOTE_FS4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_FS4, NOTE_A4, NOTE_B4, NOTE_D5,
  NOTE_A4, NOTE_G4, NOTE_FS4, NOTE_E4, NOTE_D4, 0

};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations1[] = {

  4, 4, 4, 4, 4, 4, 2, 2,
  4, 4, 4, 4, 4, 4, 2, 4,
  4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 2, 2  

};

int melody2[] = {
  NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5,
  NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5, 
  NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5,
  NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_G5,
  NOTE_C6, NOTE_D6, NOTE_E6, NOTE_D6, NOTE_C6, NOTE_B5, NOTE_A5, NOTE_G5,
  NOTE_A5, NOTE_B5, NOTE_C6, NOTE_D6, NOTE_B5, NOTE_G5, NOTE_A5, NOTE_G5

};

int noteDurations2[] = {

  8, 8, 8, 4, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 2,
  8, 8, 8, 4, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 4,
  8, 8, 8, 8, 8, 8, 8, 8, 2
};

int melody3[] = {
  NOTE_G4, NOTE_F4, NOTE_B4, NOTE_D5,
  NOTE_A4, NOTE_E4, NOTE_C5, NOTE_E5,
  NOTE_D5, NOTE_G4, NOTE_G4, NOTE_A4,
  NOTE_B4, NOTE_G4, NOTE_B4, NOTE_C5
};

int noteDurations[] = {
  8, 8, 8, 8,
  8, 8, 8, 8,
  4, 4, 4, 4,
  2, 4, 4, 2
};

void setup() {

  Serial.begin(9600);
  // iterate over the notes of the melody:
}

void loop() {
  while (Serial.available() == 0) {
    input = Serial.parseInt();
    delay(100);
  }

  if (input == 1) {
    Serial.println("Now playing: Pokemon Route 1 Theme");
  for (int thisNote = 0; thisNote < sizeof(melody1) / sizeof(melody1[0]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations1[thisNote];

    tone(8, melody1 [thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);

  }
} else if (input == 2) {
  Serial.println("Now playing: Pokemon Pallet Town Theme");  
  for (int thisNote = 0; thisNote < sizeof(melody2) / sizeof(melody2[0]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations2[thisNote];

    tone(8, melody2 [thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);
}
} else if (input == 3) {
  Serial.println("Now playing: Pokemon Intro Theme");
  for (int thisNote = 0; thisNote < sizeof(melody3) / sizeof(melody3[0]); thisNote++) {

    // to calculate the note duration, take one second divided by the note type.

    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.

    int noteDuration = 1000 / noteDurations[thisNote];

    tone(8, melody3 [thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.

    // the note's duration + 30% seems to work well:

    int pauseBetweenNotes = noteDuration * 1.30;

    delay(pauseBetweenNotes);

    // stop the tone playing:

    noTone(8);
  }
}
input = 0;
}