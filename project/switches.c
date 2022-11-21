#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "main.h"
#include "lcdutils.h"
#define RED_LED BIT0;


char switch_state_down, switch_state_changed, blink_count, blink_count2, seconds; /* effectively boolean */
int master, x;



static char switch_update_interrupt_sense()

{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  return p2val;
}
void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE |= SWITCHES;    /* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  //led_update();

}
void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();
  switches = ~p2val & SWITCHES;
}
