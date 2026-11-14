#include <reg51.h>
#include "pins.h"
#include "delay.h"
#include "functions.h"

void main(void)
{
    while(1)
    {
        keypad_scan();
        display_digit(key);
        led_control(key);
    }
}