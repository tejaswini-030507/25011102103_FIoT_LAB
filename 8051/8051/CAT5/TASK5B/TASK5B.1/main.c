#include <reg52.h>
sbit LED = P1^0;
void main(void) {
    unsigned char pwm_tick = 0;
    unsigned char duty_cycle = 0;
    bit brightening = 1;
    unsigned int fade_delay = 0;
    TMOD=0x01; 
    TH0 = 0xFE;
    TL0 = 0xA3;
    TR0 = 1;      

    while(1) {
        if (TF0 == 1) {
            TF0 = 0; 
            TR0 = 0;
            TH0 = 0xFE;
            TL0 = 0xA3;
            TR0 = 1;  
            pwm_tick++;
            if (pwm_tick >= 20) {
                pwm_tick = 0;
            }
            if (pwm_tick < duty_cycle) {
                LED = 1;
            } else {
                LED = 0;
            }
            fade_delay++;
            if (fade_delay >= 200) { 
                fade_delay = 0;
                if (brightening) {
                    duty_cycle++;
                    if (duty_cycle >= 20) brightening = 0;
                } else {
                    duty_cycle--;
                    if (duty_cycle == 0) brightening = 1;
                }
            }
        }
    }
}
