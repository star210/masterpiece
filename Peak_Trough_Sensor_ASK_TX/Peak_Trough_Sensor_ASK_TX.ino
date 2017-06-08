#include <VirtualWire.h>
char *controller;

int pulsePin = A0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat

volatile int Signal;                // holds the incoming raw data
volatile int rawSignal;
volatile int P = 512;                     // used to find peak in pulse wave, seeded
volatile int T = 512;                     // used to find trough in pulse wave, seeded
volatile int thresh = 300;                // used to find instant moment of heart beat, seeded
volatile int amp = 0;                   // used to hold amplitude of pulse waveform, seeded

volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat".
volatile boolean Transmit = false;  // "True when a transmission has been made

void setup() {

  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(blinkPin, OUTPUT);        // pin that will blink to your heartbeat!

  // ASK Radio setup

  vw_set_ptt_inverted(true); //
  vw_set_tx_pin(4);  // data out pin
  vw_setup(4000);//  speed of data transfer Kbps
}

void loop() {

  rawSignal = analogRead(pulsePin);              // read the Pulse Sensor
  Signal = map(rawSignal, 810, 700, 1, 1023);

  if (Signal < T) {                       // T is the trough
    T = Signal;                       // If T is lower then its the new trough

  }

  if (Signal > thresh && Signal > P) {        // thresh condition helps avoid noise
    P = Signal;                             // P is the peak
  }

  if ( (Signal > thresh) && (Pulse == false) ) {
    Pulse = true;                               // set the Pulse flag when we think there is a pulse
    digitalWrite(blinkPin, HIGH);               // turn on pin 13 LED
    Serial.println("LED ON");

    if ( Transmit == true ) {
      Transmit = false;
      controller = "1"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      Serial.println("TX ON");
    }
  }
  if (Signal < thresh && Pulse == true) {  // when the values are going down, the beat is over
    digitalWrite(blinkPin, LOW);           // turn off pin 13 LED
    Pulse = false;                         // reset the Pulse flag so we can do it again
    Serial.println("LED OFF");

    if ( Transmit == false ) {
      Transmit = true;
      controller = "0"  ;
      vw_send((uint8_t *)controller, strlen(controller));
      vw_wait_tx(); // Wait until the whole message is gone
      Serial.println("TX OFF");
    }

    P = thresh;                            // reset these for next time
    T = thresh;

  }
  //  Serial.print(rawSignal);
  //  Serial.print(",");
  //  Serial.print(thresh);
  //  Serial.print(",");
  //  Serial.print(Signal);
  //  Serial.print(",");
  //  Serial.print(P);
  //  Serial.print(",");
  //  Serial.println(T);

  delay(10);   // delay to allow ADC to stabilise

  amp = P - T;                           // get amplitude of the pulse wave
  thresh = amp / 2 + T;                  // set thresh at 50% of the amplitude


}



