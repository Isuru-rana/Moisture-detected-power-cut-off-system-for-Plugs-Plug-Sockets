/*
  Plug Base Device Code - Moisture Detected Power Cut Off System

  Description:
  This Arduino code is designed for the plug base device in a Moisture Detected Power Cut Off System.
  The system uses capacitive sensors to detect the presence of a human hand and tiny conductors to sense potential conductive materials during the plugin process. If hazards are detected, the plug base wirelessly communicates with plug tops to initiate a power cut-off mechanism.

  Author:
  Isuru Ranaweera
  GitHub: https://github.com/Isuru-rana

  Date:
  14/02/2022

  Notes:
  - This code is designed for the Attiny85 microcontroller.
  - It is part of an experimental project, and further research and development are recommended.
  - Tested in the Arduino IDE compiler in 2021.
  - The project didn't continue beyond the testing phase.

  Key Components:
  - Capacitive sensors for detecting human hand touch.
  - Tiny conductors to sense potential conductive materials.
  - 433MHz RF communication for wireless communication between plug bases and plug tops.

  How It Works:
  1. Continuously monitor capacitive sensors and conductive elements.
  2. If a hand touch and conductive material are detected, initiate moisture detection.
  3. Communicate wirelessly with plug tops using 433MHz RF protocol.
  4. Send a power cut-off signal to plug tops upon detecting hazards.
  5. Plug tops cut off power to prevent hazards.
  6. Safely activate power after detecting that the hand is removed.

*/

// Code for ATmega328 (arduino Uno/Nano)

#define Relay 4
#define LED 6
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  pinMode(Relay, OUTPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  mySwitch.enableReceive(0);
}

int val;
long on_time;
boolean state = false;

void loop() {
  Serial.print(millis());
  Serial.print(" / ");

  if (mySwitch.available()) {
    val = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();
  }

  if (val == 4001) {
    digitalWrite(Relay, HIGH);
    digitalWrite(LED, HIGH);
    delay(2000);
    on_time = millis();
    state = true;
    val = 0;
    // E. I. M. RANAWEERA | BT/EE/21/22 44
  }

  if (state == true && millis() - on_time > 10000) {
    digitalWrite(Relay, LOW);
    digitalWrite(LED, LOW);
    delay(20);
    digitalWrite(LED, HIGH);
    delay(20);
    digitalWrite(LED, LOW);
    val = 0;
    state = false;
    on_time = 0;
  }

  if (val == 4101) {
    digitalWrite(Relay, LOW);
    digitalWrite(LED, LOW);
    delay(20);
    digitalWrite(LED, HIGH);
    delay(20);
    digitalWrite(LED, LOW);
    val = 0;
    state = false;
    on_time = 0;
  }

  Serial.println(on_time);
}

