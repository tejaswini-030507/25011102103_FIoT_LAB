#include <reg51.h>
#include "pins.h"
#include "functions.h"

unsigned int count = 0;

void timer0_init(void)
{
    TMOD = 0x01;

    TH0 = 0xFA;
    TL0 = 0x9A;

    TR0 = 1;

    while(1)
    {
        if(TF0 == 1)
        {
            TF0 = 0;

            count++;

            TH0 = 0xFA;
            TL0 = 0x9A;

            if(count >= 533)
            {
                led = ~led;
                count = 0;
            }
        }
    }
}