//Stepper
#include <reg51.h>

unsigned char count = 0;
unsigned char speed = 1;
unsigned char step = 0x08;

int keypad(void)
{
    static const int key[4][4] =
    {
        {1, 2, 3, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1},
        {-1, -1, -1, -1}
    };

    static const unsigned char rowpin[4] = {7, 6, 5, 4};
    static const unsigned char colpin[4] = {3, 2, 1, 0};

    int row, col;

    for(row = 0; row < 4; row++)
    {
        P2 |= 0xF0;
        P2 &= ~(1 << rowpin[row]);

        for(col = 0; col < 4; col++)
        {
            if((P2 & (1 << colpin[col])) == 0)
            {
                return key[row][col];
            }
        }
    }

    return -1;
}

void motor(void)
{
    P1 = (P1 & 0xF0) | step;

    if(step == 0x01)
    {
        step = 0x08;
    }
    else
    {
        step = step >> 1;
    }
}

void setspeed(int k)
{
    switch(k)
    {
        case 1: speed = 1; break;
        case 2: speed = 5; break;
        case 3: speed = 10; break;
    }
}

void timer0(void) interrupt 1
{
    TH0 = 0xDC;
    TL0 = 0x00;

    count++;

    if(count >= speed)
    {
        count = 0;
        motor();
    }
}

void timerinit(void)
{
    TMOD = 0x01;

    TH0 = 0xDC;
    TL0 = 0x00;

    ET0 = 1;
    EA = 1;
    TR0 = 1;
}

void main(void)
{
    P1 = 0x08;

    timerinit();

    while(1)
    {
        int k = keypad();

        if(k != -1)
        {
            setspeed(k);
        }
    }
}