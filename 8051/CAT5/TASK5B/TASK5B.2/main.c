#include <reg52.h>
sbit WAVE_OUT = P1^1;  // Output pin
void main(void) {
    unsigned char wave_mode = 3; 
    unsigned char reload_high = 0xFE;
    unsigned char reload_low  = 0x33;
    switch(wave_mode) {
        case 1: // 100 Hz (Toggle interval = 5000 us)
            reload_high = 0xEE; reload_low = 0x00; break;
        case 2: // 500 Hz (Toggle interval = 1000 us)
            reload_high = 0xFC; reload_low = 0x66; break;
        case 3: // 1 kHz  (Toggle interval = 500 us)
            reload_high = 0xFE; reload_low = 0x33; break;
        case 4: // 2 kHz  (Toggle interval = 250 us)
            reload_high = 0xFF; reload_low = 0x1A; break;
        case 5: // 5 kHz  (Toggle interval = 100 us)
            reload_high = 0xFE; reload_low = 0xA4; break;
        default: // Default fallback to 1 kHz
            reload_high = 0xFE; reload_low = 0x33;
    }
    TMOD = 0x01;
    TH0 = reload_high;
    TL0 = reload_low;
    TR0 = 1;   
    while(1) {
        if (TF0 == 1) {
            TF0 = 0;   
            TR0 = 0;             
            TH0 = reload_high;  
            TL0 = reload_low;  
            TR0 = 1;    
            WAVE_OUT = ~WAVE_OUT; 
        }
    }
}
