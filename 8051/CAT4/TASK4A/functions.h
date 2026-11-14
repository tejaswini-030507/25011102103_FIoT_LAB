#ifndef FUNCTIONS_H
#define FUNCTIONS_H

extern unsigned char key;
void keypad_scan(void);
void display_digit(unsigned char value);
void led_control(unsigned char key);
void running_led(void);
void binary_counter(void);
void alternate_led(void);
void blink_all(void);
void pattern_delay(unsigned char current_key);

#endif