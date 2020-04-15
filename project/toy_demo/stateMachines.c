#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateAssembly.h"

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

      switch(song_play(delay)) {
        case 0:
	  __delay_cycles(0);
	  break;
        case 1:
	  __delay_cycles(5000);
	  break;
        case 2:
	  __delay_cycles(10000);
	  break;

	case 3:
	  __delay_cycles(60000);
	  break;
	}
    }

}

void song(){
  for(int i= 0; i < 2;i++){
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 0);
  play(1318, 1);
  play(0, 0);
  play(1174, 1);
  play(0, 2);
  play(987, 1);
  play(0, 0);
  play(1046, 1);
  play(0, 0);
  play(987, 1);
  play(0, 0);
  play(783, 1);
  play(0, 0);
  play(659, 1);
  play(0, 0);
  play(587, 1);
  play(0, 2);
  play(659, 1);
  play(0, 0);
  play(783, 1);
  play(0, 0);
  play(659, 1);
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 2);
  play(698, 1);
  play(0, 0);
  play(880, 1);
  play(0, 0);
  play(987, 1);
  play(0, 2);
  play(1318, 1);
  play(0,0);
  play(1174, 1);
  play(0, 2);
  play(987, 1);
  play(0, 0);
  play(1046, 1);
  play(0, 0);
  play(1318, 1);
  play(0, 3);
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
  else if(switch_state_down2){
    changed = toggle_red();
    led_changed = changed;
    led_update();
  }

  led_changed = changed;

  led_update();

}
