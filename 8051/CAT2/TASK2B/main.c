#include <reg51.h>
#include "delay.h"

sbit led = P1^7;

void main(void)
{
    while(1)
    {
        led = 0;
        delay_1Hz();

        led = 1;
        delay_1Hz();
    }
}