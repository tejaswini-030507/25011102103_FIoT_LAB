//Pulse train mode
#include <reg51.h>

sbit out = P1^1;

unsigned char i = 0;

void timer1(void) interrupt 3
{
    TH1 = 0xFC;
    TL1 = 0x66;

    if(i == 0)
    {
        out = 1;
    }
    else
    {
        out = 0;
    }

    i++;

    if(i >= 8)
    {
        i = 0;
    }
}

void main(void)
{
    out = 0;

    TMOD = 0x10;

    TH1 = 0xFC;
    TL1 = 0x66;

    ET1 = 1;
    EA = 1;
    TR1 = 1;

    while(1)
    {
    }
}