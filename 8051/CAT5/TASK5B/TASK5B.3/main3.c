//Burst signal
#include <reg51.h>

sbit out = P1^1;

unsigned char i = 0;

void timer1(void) interrupt 3
{
    TH1 = 0xFC;
    TL1 = 0x66;

    if(i < 10)
    {
        out = ~out;
    }
    else if(i < 20)
    {
        out = 0;
    }
    else
    {
        out = ~out;
    }

    i++;

    if(i >= 30)
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