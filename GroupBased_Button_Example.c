#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Für mehr Informationen, welche Pins für welche konstanten sind
//siehe Datenblatt Seite 19 in der Spalte PCINT und PAD

void init_groupbased_button();

int main() {
    sei();
    init_groupbased_button();
    while(1);
}

void init_groupbased_button(){
    PORTD |= (1<<PORTD4) | (1<<PORTD5)          //Einschalten des PIND4(PCINT20) und PIND5(PCINT21) (Die pins einschalten, die an buttons sind)
    PCICR |= (1<<PCIE2)                         //Register aktivieren (PCIE0: B | PCIE1: C | PCIE2: D)
    PCMSK2 |= (1 << PCINT20) | (1 << PCINT21)   //Aktivieren der interrupts an den bestimmten pins
}

ISR (PCINT2_vect) {                //Andere Interrupts sind PCINT0_vect und PCINT1_vect
  if(!(PIND & (1<<PIND4))){        //Taste an PIND4 betätigt
  }

  if(!(PIND & (1<<PIND5))){        //Taste an PIND5 betätigt
  }
    _delay_ms(70); //Delay um Prellen zu verhindern
}

