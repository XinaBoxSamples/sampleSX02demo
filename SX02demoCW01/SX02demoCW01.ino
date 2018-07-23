 #include <xCore.h>
#include <xOD01.h>
#include <ESP8266WiFi.h>
#include "TIMER_CTRL.h"
#include <xSX01.h>          // include analogue input sensor library
#include <math.h>           // include maths functions

#define C_Kelvin 273.15     // for conversion from kelvin to celsius
#define series_res 10000    // value of series resistor in ohms
#define B 3950              // B parameter for thermistor
#define room_tempK 298.15   // room temperature in kelvin
#define room_res 10000      // resistance at room temperature in ohms
#define vcc 3.3             // supply voltage

xSX01 SX01(0x55);           // set the i2c address

float voltage;              // variable containing the measured voltage (0 - 3.3V)
float therm_res;            // thermistor resistance
float act_tempK;            // actual temperature kelvin
float act_tempC;            // actual temperature in celsius

unsigned long currentMilli = 0;
int ledID = 0;
bool fade_flag1 = true;
unsigned long previousMilli1 = 0;    // timing variable for LEDS
int LED_state1 = 0;
bool fade_flag2 = true;
unsigned long previousMilli2 = 0;    // timing variable for LEDS
int LED_state2 = 0;
bool fade_flag3 = true;
unsigned long previousMilli3 = 0;    // timing variable for LEDS
int LED_state3 = 0;


void setup() {
  // put your setup code here, to run once:
  setup_program();
}

void loop() {
  // put your main code here, to run repeatedly:
  main_program();
}
