#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_simple_button();

int main() {

    init_simple_button();
    while(1);
}

void init_simple_button(){
    EIMSK |= (1<<INT0) | (1<<INT1)        //Interrupts Int0 und Int1 aktivieren
    PORTD |= (1<<PORTD2) | (1<<PORTD3)    //Einschalten des PIND2(INT0) und PIND3(INT1)
}

ISR(INT0_vect){
    //Button on PD2 was pressed
}

ISR(INT1_vect){
    //Button on PD3 was pressed
}