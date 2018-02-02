#ifndef _PORTF_H
#define _PORTF_H

void portF_init(
    uint8_t pinnumber; //HEX
    uint8_t io; //HEX
    uint8_t unlock; //boolean 1-> locked 0->unlocked
    volatile unsigned long delay);

#endif
