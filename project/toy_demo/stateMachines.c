#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"


char toggle_red()/* always toggle! */

{

  static char state = 0;



  switch (state) {

  case 0:

    red_on = 1;

    state = 1;

    break;

  case 1:

    red_on = 0;

    state = 0;

    break;

  }

  return 1;/* always changes an led */

}

void dim_red(){

  red_on = 0;
}



void state_advance()/* alternate between toggling red & green */

{

  char changed = 0;

  if(switch_state_down){

    changed = toggle_red();
  }
  else if(switch_state_down1){
    dim_red();
  }

  led_changed = changed;

  led_update();

}
