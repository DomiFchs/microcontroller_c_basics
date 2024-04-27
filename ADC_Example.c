#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
The term 'Atomic Block' simply denotes that it cannot be interrupted. 
It requires two clock cycles until the ADC value is written in. 
But if the ISR were to be triggered again after the first cycle, it could lead to undesired consequences.
Although it might become inconsequential after the next display overwrite, it nonetheless presents an undesirable situation
*/

void init_adc();

int main() {
    sei();
    init_adc();
    while(1);
}

void init_adc(){
    ADMUX |= (1<<REFS0)
    ADMUX |= (1<<MUX0) | (1<<MUX2)          // Aktivieren des ADCs für PINC5
    ADCSRA |= (1<<ADEN)                     //ADC Enable
    ADCSRA |= (1<<ADIE)                     //ADC Interrupt Enable
    ADCSRA |= (1<<ADATE)                    //Immer, so schnell wie möglich triggern
    ADCSRA |= (1<<ADPS0) | (1<<ADPS1) (1<<ADPS2)    //Prescaler setzen
    ADCSRA |= (1<<ADSC);                    //Messung starten
}

ISR(ADC_vect){

    ATOMIC_BLOCK(ATOMIC_FORCEON){ //Alle ISRs werden in diesem Block deaktviert.
        float value = (float)ADCW; //Gemessener Wert auslesen
        float volt = (value / 1023.0) * 5.0 ; //berechnung der Volt
    }

}


