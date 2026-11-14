#ifndef PINS_H
#define PINS_H
#include <reg51.h>

// Keypad Rows
sbit r1 = P2^3;
sbit r2 = P2^2;
sbit r3 = P2^1;
sbit r4 = P2^0;

// Keypad Columns
sbit c1 = P2^7;
sbit c2 = P2^6;
sbit c3 = P2^5;
sbit c4 = P2^4;

//LED
sbit led1 = P1^1;
sbit led2 = P1^2;
sbit led3 = P1^3;
sbit led4 = P1^4;

//Seven Segment Display
#define seg P0

#endif