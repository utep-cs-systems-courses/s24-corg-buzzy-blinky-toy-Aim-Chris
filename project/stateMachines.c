#include <msp430.h>
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"

void switch_state_advance(){
  switch(switch_state){
  case 1:
    sound();
    break;
  }
}
