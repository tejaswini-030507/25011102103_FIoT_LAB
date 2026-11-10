#include <reg51.h>

sbit led1 = P1^1;

unsigned int count = 0;
unsigned int pwm_count = 0;
unsigned int fade_count = 0;
unsigned int inc = 1;

void main(){
	led1 = 0;
	TMOD = 0x01;
	TL0 = 0x98;
	TH0 = 0xFA;
	TR0 = 1;
	while(1){
		if (TF0 == 1){
			TL0 = 0x98;
			TH0 = 0xFA;
			TF0 = 0;
			pwm_count++;
			if (pwm_count >= 100){
				pwm_count = 0;
			}
			if (pwm_count < count){
				led1 = 0;
			}
			else{
				led1 = 1;
			}
			fade_count++;
			if (fade_count >= 500){
				fade_count = 0;
				if (inc == 1){
					count += 10;
					if (count >= 100){
						count = 100;
						inc = 0;
					}
				}
					else{
						count -= 10;
						if (count ==0){
							inc = 1;
						}
					}
				}
			TR0 = 1;
		}
	}
}
			
