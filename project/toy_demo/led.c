#include <msp430.h>
#include "led.h"
#include "switches.h"

unsigned char red_on = 0;

unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED};

void led_init()

{

  P1DIR |= LEDS;// bits attached to leds are output

  switch_state_changed = 1;

  led_update();

}



void led_update(){

  char ledFlags = 0;
  
  if (switch_state_changed) {


    ledFlags |= switch_state_down ? LED_RED: 0;
    
    ledFlags = redVal[red_on];
     
    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds
     
    P1OUT |= ledFlags;     // set bit for on leds

    led_changed = 0;
     
  }
  if (led_changed && switch_state_down2) {

    ledFlags = redVal[red_on];


    P1OUT &= (0xff^LEDS) | ledFlags; // clear bit for off leds

    P1OUT |= ledFlags;     // set bit for on leds

    led_changed = 0;

  }

  switch_state_changed = 0;

}
