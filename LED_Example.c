#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

void init_led();

int main() {

    init_led();
    
    while(1){
        turn_on_led();
        _delay_ms(1000);

        turn_off_led();
        _delay_ms(1000);
    }
}

void init_led(){
    DDRD |= (1 << PORTD5); // Set PD5 as output
    PORTD &= ~(1 << PORTD5); //make sure the LED is off
}

void turn_on_led(){
    PORTD |= (1 << PORTD5); // Turn on the LED
}

void turn_off_led(){
    PORTD &= ~(1 << PORTD5); // Turn off the LED
}
