/*
  Moisture Detected Power Cut Off System for Plugs & Plug Sockets

  Description:
  This Arduino code is designed for the plug base microcontroller, implementing a Moisture Detected Power Cut-Off System.
  The system actively monitors capacitive sensors and conductive elements to detect the presence of a human hand and potential conductive materials during the plugin process. If hazards are detected, the system wirelessly communicates with plug tops and initiates a power cut-off mechanism to prevent hazards.

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
  - Conductive elements to sense potential conductive materials.
  - 433MHz RF communication for wireless communication between plug bases and plug tops.

  How It Works:
  1. Continuously monitor capacitive sensors and conductive elements.
  2. If a hand touch and conductive material are detected, initiate moisture detection.
  3. Communicate wirelessly with plug tops using 433MHz RF protocol.
  4. Send a power cut-off signal to plug tops upon detecting hazards.
  5. Plug tops cut off power to prevent hazards.
  6. Safely activate power after detecting that the hand is removed.

*/


// Code for Attiny 85A

#include <CapacitiveSensor.h>
#include <RCSwitch.h>

#define TX_Pin 0
#define Short_Sensor 4
#define Detect_LED 1

CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);
RCSwitch mySwitch = RCSwitch();

long val = 0;
long val1 = 0;
boolean b = true;
boolean msg = false;

void setup() {
  pinMode(Detect_LED, OUTPUT);
  pinMode(Short_Sensor, INPUT);
  mySwitch.enableTransmit(TX_Pin);
}

void loop() {
  long start = millis();
  long total1 = cs_2_3.capacitiveSensor(30);
  val1 = map(total1, 0, 320000, 0, 100);

  int Short_Read = analogRead(Short_Sensor);
  float Short_val = Short_Read * (5.0 / 1023.0);

  if (val1 > 11 && Short_val < 1.4) {
    digitalWrite(Detect_LED, HIGH);
    delay(100);
    digitalWrite(Detect_LED, LOW);
    sw_send(1);
    msg = true;
  }

  if (msg == true) {
    if (val1 < 11 || Short_val > 1.4) {
      digitalWrite(Detect_LED, LOW);
      sw_send(0);
      msg = false;
    }
  }

  digitalWrite(Detect_LED, HIGH);
  delay(10);
  digitalWrite(Detect_LED, LOW);
  delay(20);
}

void sw_send(boolean val) {
  if (val == 1) {
    mySwitch.send(4001, 24);
    delay(500);
    mySwitch.send(4001, 24);
    delay(500);
    digitalWrite(Detect_LED, HIGH);
    delay(50);
    digitalWrite(Detect_LED, LOW);
  } else {
    mySwitch.send(4101, 24);
    delay(500);
    mySwitch.send(4101, 24);
    delay(500);
  }
}
