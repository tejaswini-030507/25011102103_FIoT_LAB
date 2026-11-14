#include <reg51.h>

void main()
{
    char ch;
    TMOD = 0x20;
    TH1 = 0xFA;
    SCON = 0x50;

    TR1 = 1;

    while(1)
    {
        while(RI == 0);
        ch = SBUF;
        RI = 0;
        SBUF = ch;
        while(TI == 0);
        TI = 0;
    }
}