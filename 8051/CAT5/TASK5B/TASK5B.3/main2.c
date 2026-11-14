//Variable duty cycle
#include <reg51.h>

sbit led = P1^0;

unsigned char count = 0;
unsigned char duty = 0;

unsigned char fcount = 0;
unsigned char dir = 1;

void timer1(void) interrupt 3
{
    TH1 = 0xFF;
    TL1 = 0xF7;

    if(count < duty)
    {
        led = 1;
    }
    else
    {
        led = 0;
    }

    count++;

    if(count >= 100)
    {
        count = 0;

        fcount++;

        if(fcount >= 10)
        {
            fcount = 0;

            if(dir == 1)
            {
                duty++;

                if(duty >= 100)
                {
                    duty = 100;
                    dir = 0;
                }
            }
            else
            {
                if(duty > 0)
                {
                    duty--;
                }

                if(duty == 0)
                {
                    dir = 1;
                }
            }
        }
    }
}

void main(void)
{
    led = 0;

    TMOD = 0x10;

    TH1 = 0xFF;
    TL1 = 0xF7;

    ET1 = 1;
    EA = 1;
    TR1 = 1;

    while(1)
    {
    }
}