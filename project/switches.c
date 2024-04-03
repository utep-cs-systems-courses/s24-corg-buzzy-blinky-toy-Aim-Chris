#include <msp430.h>
#include "switches.h"
#include "buzzer.h"
#include "stateMachines.h"

char state1, state2, state3, state4, switch_state_changed;
static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  state1 = (p2val & SW1) ? 0 : SW1;
  state2 = (p2val & SW2) ? 0 : SW2;
  state3 = (p2val & SW3) ? 0 : SW3;
  state4 = (p2val & SW4) ? 0 : SW4;

  if(state1){
    sound();
  }
}
