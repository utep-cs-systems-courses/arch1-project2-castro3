#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"

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

void play(int note, int delay) {
  
  for(int i =0; i < 500; i++) {

      buzzer_set_period(note);

      switch(delay) {
        case 0:
	  __delay_cycles(0);
	  break;
        case 50:
	  __delay_cycles(5000);
	  break;
        case 100:
	  __delay_cycles(10000);
	  break;

	case 600:
	  __delay_cycles(60000);
	  break;
	}
    }

}

void song(){
  for(int i= 0; i < 2;i++){
  play(0, 200);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 100);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 100);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 0);
  play(1318, 50);
  play(0, 0);
  play(1174, 50);
  play(0, 100);
  play(987, 50);
  play(0, 0);
  play(1046, 50);
  play(0, 0);
  play(987, 50);
  play(0, 0);
  play(783, 50);
  play(0, 0);
  play(659, 50);
  play(0, 0);
  play(587, 50);
  play(0, 100);
  play(659, 50);
  play(0, 0);
  play(783, 50);
  play(0, 0);
  play(659, 50);
  play(0, 100);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 100);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 100);
  play(698, 50);
  play(0, 0);
  play(880, 50);
  play(0, 0);
  play(987, 50);
  play(0, 100);
  play(1318, 50);
  play(0,0);
  play(1174, 50);
  play(0, 100);
  play(987, 50);
  play(0, 0);
  play(1046, 50);
  play(0, 0);
  play(1318, 50);
  play(0, 600);
  }

}


void state_advance()/* alternate between toggling red & green */

{

  char changed = 0;

  if(switch_state_down){

    changed = toggle_red();
  }
  else if(switch_state_down1){
    song();
  }

  led_changed = changed;

  led_update();

}
