
#include <avr/io.h>
#include <avr/eeprom.h>

int main(void)
{
    int valueToWrite = 1234;
    eeprom_write_word(0x00, valueToWrite); // write 1234 to the eeprom at address 0x00


    uint16_t value = eeprom_read_word(0x00); //0x00 is the address of the eeprom value

    while (1);
}