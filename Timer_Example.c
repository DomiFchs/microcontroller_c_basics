#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_timer();

int main() {

    sei();
    init_timer();
    while(1);
}

void init_timer(){
    TCCR1B |= (1 << WGM12) | (1 << CS12) | (1 << CS10);
    TIMSK1 |= (1 << OCIE1A);
    OCR1A = 15626;                                 //1 Sekunde Setzen
}

ISR(TIMER1_COMPA_vect){   //Wird ausgeführt, wenn die gesetzte zeit des Timers vorbei ist
    //code here
}


