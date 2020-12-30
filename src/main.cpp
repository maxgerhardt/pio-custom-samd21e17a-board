#include <Arduino.h>

void setup() {
  /* 
   * use arduino pins D0..D13, A0-A4, D19-D22 as listed / mapped in 
   * custom_arduino_variant/custom_atsamd21e17a/variant.cpp 
   */
  pinMode(0, OUTPUT); /* D0 = Port A pin 8 (PA8)*/

  /* can also use direct register accesss (see wiring_digital.c of Adafruit SAMD core) */
  PORT->Group[PORTA].PINCFG[27].reg=(uint8_t)(PORT_PINCFG_INEN); /* PA 27 support reading back current value (even as output pin) */
  PORT->Group[PORTA].DIRSET.reg = (1 << 27); /* PA 27 set direction to ouput */
  PORT->Group[PORTA].OUTCLR.reg = (1 << 27); /* PA 27 to LOW (clear)*/
  PORT->Group[PORTA].OUTSET.reg = (1 << 27); /* PA 27 to HIGH (set)*/

  Serial.begin(115200); /* Start USB-CDC serial driver */
  Serial1.begin(115200); /* start hardware UART (TX = PA06, RX = PA07) */
  Serial1.println("Hello world!");
}

void loop() {
  digitalWrite(0, HIGH); /* PA8 high */
  delay(500);
  digitalWrite(0, LOW); /* PA8 low */
  delay(500);
}