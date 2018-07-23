void setup_program(void) {
  // Set the I2C Pins for CW01
#ifdef ESP8266
 Wire.pins(2, 14);
 Wire.setClockStretchLimit(15000);
 Wire.begin();
#else
 // Start the I2C Comunication
 Wire.begin();
#endif

  // disable wifi
  WiFi.forceSleepBegin();
  voltage = 0;
  therm_res = 0;
  act_tempK = 0;
  act_tempC = 0;

  // set and start i2c bus
  Wire.begin(2, 14);

  // start sensor
  SX01.begin();

  // start oled
  OLED.begin();

  // clear oled
  OD01.clear();

  // set output leds
  pinMode(CW01_RED, OUTPUT);
  pinMode(CW01_GREEN, OUTPUT);
  pinMode(CW01_BLUE, OUTPUT);

  // turn rgb on
  digitalWrite(CW01_RED, HIGH);
  digitalWrite(CW01_GREEN, HIGH);
  digitalWrite(CW01_BLUE, HIGH);

  delay(2000);

  // turn rgb off
  digitalWrite(CW01_RED, LOW);
  digitalWrite(CW01_GREEN, LOW);
  digitalWrite(CW01_BLUE, LOW);
  
  delay(1000);
  t.tick_main = millis();
  t.tick_poll = millis();
}

