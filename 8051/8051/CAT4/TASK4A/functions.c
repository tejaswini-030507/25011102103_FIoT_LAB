#include "functions.h"
#include "pins.h"
#include "delay.h"

unsigned char key = 0;
//To determine which key is pressed
void keypad_scan(void){
    // Row 1
    r1 = 0; r2 = 1; r3 = 1; r4 = 1;

    if(c1 == 0)
    {
        delay(20);
        while(c1 == 0);
        key = 1;
        return;
    }
    else if(c2 == 0)
    {
        delay(20);
        while(c2 == 0);
        key = 4;
        return;
    }
    else if(c3 == 0)
    {
        delay(20);
        while(c3 == 0);
        key = 7;
        return;
    }
    else if(c4 == 0)
    {
        delay(20);
        while(c4 == 0);
        key = 14;      // *
        return;
    }

    // Row 2
    r1 = 1; r2 = 0; r3 = 1; r4 = 1;

    if(c1 == 0)
    {
        delay(20);
        while(c1 == 0);
        key = 2;
        return;
    }
    else if(c2 == 0)
    {
        delay(20);
        while(c2 == 0);
        key = 5;
        return;
    }
    else if(c3 == 0)
    {
        delay(20);
        while(c3 == 0);
        key = 8;
        return;
    }
    else if(c4 == 0)
    {
        delay(20);
        while(c4 == 0);
        key = 0;  // 0
        return;
    }

    // Row 3
    r1 = 1; r2 = 1; r3 = 0; r4 = 1;

    if(c1 == 0)
    {
        delay(20);
        while(c1 == 0);
        key = 3;
        return;
    }
    else if(c2 == 0)
    {
        delay(20);
        while(c2 == 0);
        key = 6;
        return;
    }
    else if(c3 == 0)
    {
        delay(20);
        while(c3 == 0);
        key = 9;
        return;
    }
    else if(c4 == 0)
    {
        delay(20);
        while(c4 == 0);
        key = 15; // #
        return;
    }

    // Row 4
    r1 = 1; r2 = 1; r3 = 1; r4 = 0;

    if(c1 == 0)
    {
        delay(20);
        while(c1 == 0);
        key = 10; // A
        return;
    }
    else if(c2 == 0)
    {
        delay(20);
        while(c2 == 0);
        key = 11; //B
        return;
    }
    else if(c3 == 0)
    {
        delay(20);
        while(c3 == 0);
        key = 12; // C
        return;
    }
    else if(c4 == 0)
    {
        delay(20);
        while(c4 == 0);
        key = 13;      // D
        return;
    }

}

//Common Cathode table
unsigned char seg_code[] =
{
    0x3F,   // 0
    0x06,   // 1
    0x5B,   // 2
    0x4F,   // 3
    0x66,   // 4
    0x6D,   // 5
    0x7D,   // 6
    0x07,   // 7
    0x7F,   // 8
    0x6F,   // 9
    0x77,   // A
    0x7C,   // b
    0x39,   // C
    0x5E,   // d
	  0x79,   // e
	  0x71    // f

};

//To display in seven segment display
void display_digit(unsigned char value)
{
    if(value <= 9)
    {
        seg = seg_code[value];
    }
}

//Overall control wrt key pressed
void led_control(unsigned char key){
    led1 = 0;
    led2 = 0;
    led3 = 0;
    led4 = 0;

    switch(key)
    {
        case 1:
            led1 = 1;
            break;

        case 2:
            led2 = 1;
            break;

        case 3:
            led3 = 1;
            break;

        case 4:
            led4 = 1;
            break;

        case 5:
            running_led();
            break;

        case 6:
            alternate_led();
            break;

        case 7:
            binary_counter();
            break;

        case 8:
            blink_all();
            break;

        case 0:
            break;
    }
}

// Wait while continuously checking for a new key
void pattern_delay(unsigned char current_key)
{
    unsigned char i;

    for(i = 0; i < 50; i++)
    {
        delay(20);
        keypad_scan();

        if(key != current_key)
        {
            return;
        }
    }
}


// Running LED Pattern
void running_led(void)
{
    led1 = led2 = led3 = led4 = 0;

    led1 = 1;
    pattern_delay(5);
    if(key != 5) return;

    led1 = 0;
    led2 = 1;
    pattern_delay(5);
    if(key != 5) return;

    led2 = 0;
    led3 = 1;
    pattern_delay(5);
    if(key != 5) return;

    led3 = 0;
    led4 = 1;
    pattern_delay(5);
    if(key != 5) return;

    led4 = 0;
}


// Binary Counter (0-15)
void binary_counter(void)
{
    unsigned char count;

    for(count = 0; count < 16; count++)
    {
        led1 = (count >> 0) & 1;
        led2 = (count >> 1) & 1;
        led3 = (count >> 2) & 1;
        led4 = (count >> 3) & 1;

        pattern_delay(7);

        if(key != 7)
        {
            return;
        }
    }
}


// Alternate LEDs
void alternate_led(void)
{
    led1 = led3 = 1;
    led2 = led4 = 0;

    pattern_delay(6);
    if(key != 6) return;

    led1 = led3 = 0;
    led2 = led4 = 1;

    pattern_delay(6);
    if(key != 6) return;

    led1 = led2 = led3 = led4 = 0;
}


// All LEDs Blink
void blink_all(void)
{
    led1 = led2 = led3 = led4 = 1;

    pattern_delay(8);
    if(key != 8) return;

    led1 = led2 = led3 = led4 = 0;

    pattern_delay(8);
}