void main_code(void) {

  // store the volatge
  voltage = SX01.getVoltage();

  // calculate thermistor resistance
  therm_res = ((vcc * series_res) / voltage) - series_res;

  // calculate the actual temperature in kelvin
  act_tempK = (room_tempK * B) / (B + room_tempK * log(therm_res / room_res));

  // convert kelvin to celsius
  act_tempC = act_tempK - C_Kelvin;

  // print temperature on OLED display
  // manual formatting to display in center
  OD01.set2X();
  OD01.print("  ");
  OD01.print(act_tempC);
  OD01.print(" C");
  OD01.println("");
  OD01.set1X();
  OD01.println("    SX02 is an ADC");
  OD01.println("");
  
  OD01.println(" Touch the probe for");
  OD01.println("  temperature change");
  OD01.println("");
  OD01.print("       ");
  OD01.print((1.8*act_tempC)+32);
  OD01.print(" F");

}

