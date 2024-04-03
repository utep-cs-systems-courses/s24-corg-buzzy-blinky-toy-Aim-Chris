#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"
#include "switches.h"

int main(void){
  configureClocks();
  switch_init();
  buzzer_init();

  or_sr(0x18);
}
