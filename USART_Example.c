#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void init_usart();
void sendCharacter(uint8_t charToSend);
void sendString(char *str);

int main() {
    sei();
    init_usart();
    while(1);
}

void init_usart(){
    UBRR0 = 103;                //Setzen der Baudrate
    UCSR0B |= (1<<TXEN0)            //Aktivieren des Senden
    UCSR0B |= (1<<RXEN0) | (1<<RXCIE0)    //Aktivieren des Empfangen
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01)    //Größe der Bits setzen (8-Bit encoding)
}

void sendCharacter(uint8_t charToSend){
    while((!UCSR0A & (1<<UDRE0)));
    UDR0=charToSend;
}

void sendString(char *str){
    while(*str){
    sendCharacter(*str);
    *str++;
  }
}

ISR(USART_RX_vect){
    uint8_t receivedChar = UDR0;
    //do something
}

