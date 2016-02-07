#include "Wire.h"
#include "BlinkM_funcs.h"

#define blinkm_addr 0x00

void setup()
{
  BlinkM_beginWithPower();
  BlinkM_stopScript(blinkm_addr);  // turn off startup script
} 

void loop()
{
  int a = random(0, 100);
  if (a <= 50) {
  // set blinkms with hue & bri, saturation is max
    BlinkM_fadeToRGB( blinkm_addr, 255, 0, 0 );
  } else {
    BlinkM_fadeToRGB( blinkm_addr, 0, 255, 0 );
  }
  delay(random(50000, 150000));  // wait a bit because we don't need to go fast
} 
