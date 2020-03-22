#ifndef led_included
#define led_included



#define LED_RED BIT0               // P1.0
#define LEDS (BIT0)


extern unsigned char red_on;

extern unsigned char led_changed;



void led_init();

void led_update();



#endif
