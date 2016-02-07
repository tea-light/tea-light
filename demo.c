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
  // show light as red
    BlinkM_fadeToRGB( blinkm_addr, 255, 0, 0 );
  } else {
    // show light as green
    BlinkM_fadeToRGB( blinkm_addr, 0, 255, 0 );
  }
  // wait between 50 and 150 seconds to change between colours:
  // (i.e. 50 * 1000 and 150 * 1000 milliseconds )
  delay(random(50000, 150000));  
} 
