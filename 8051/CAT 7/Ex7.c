#include <reg51.h>

sbit RS = P3^2;
sbit EN = P3^3;

unsigned char k, l;

void delay()
{
    unsigned int i, j;

    for(i = 0; i < 50; i++)
    {
        for(j = 0; j < 100; j++)
        {
        }
    }
}

void enable()
{
    EN = 1;
    delay();
    EN = 0;
}

void send(unsigned char r)
{
    P3 = (P3 & 0x0F) | (r & 0xF0);
    enable();
}

void command(unsigned char r)
{
    RS = 0;

    send(r);        
    send(r << 4);   
}

void datas(unsigned char r)
{
    RS = 1;

    send(r);        
    send(r << 4);   
}

void string(char *s)
{
    while(*s != '\0')
    {
        datas(*s);
        s++;
    }
}

void lcd_init()
{
    RS = 0;
    EN = 0;

    delay();

    send(0x30);
    delay();

    send(0x30);
    delay();

    send(0x30);
    delay();

    send(0x20);
    delay();
	
    command(0x28);
    delay();

    command(0x0F);
    delay();

    command(0x01);
    delay();

    command(0x06);
    delay();
}

void main()
{
    lcd_init();

    string("HELLO WORLD");

    while(1)
    {
    }
}
