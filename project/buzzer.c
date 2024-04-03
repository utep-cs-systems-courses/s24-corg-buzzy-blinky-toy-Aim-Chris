#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
void sound(){
  int song[15]= {523,523,784,784,440,440,784,698,698,659,659,587,587,523};
  int i =0;
  while(i<16){
    buzzer_set_period(song[i]);
    __delay_cycles(4000000);
  }
  buzzer_set_period(0);
}
