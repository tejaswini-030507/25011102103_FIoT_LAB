#include <reg51.h>
sbit ledpin1 = P1^0;
sbit ledpin2 = P1^1;
sbit ledpin3 = P1^2;
sbit ledpin4 = P1^4;
sbit R1 = P2^7;
sbit R2 = P2^6;
sbit R3 = P2^5;
sbit R4 = P2^4;
sbit C1 = P2^3;
sbit C2 = P2^2;
sbit C3 = P2^1;
sbit C4 = P2^0;

unsigned char key;
int c=0;

void delay(){
    int i,j;
    for(i=0;i<200;i++){
        for(j=0;j<300;j++){

        }
    }
}

void switch_key(){
		R1 = 0;
		R2 = 1;
		R3 = 1;
		R4 = 1;
		if (C1 == 0){
			key = 0x3F;
			c=0;
			
		}
		else if (C2 == 0){
			key = 0x06;
			c=1;
		}
		else if (C3 == 0){
			key = 0x5B;
			c=2;
		}
		else if (C4 == 0){
			key = 0x4F;
			c=3;
		}
		
		R1 = 1;
		R2 = 0;
		R3 = 1;
		R4 = 1;
		if (C1 == 0){
			key = 0x66;
			c=4;
		}
		else if (C2 == 0){
			key = 0x6D;
			c=5;
		}
		else if (C3 == 0){
			key = 0x7D;
			c=6;
		}
		else if (C4 == 0){
			key = 0x07;
			c=7;
		}
		R1 = 1;
		R2 = 1;
		R3 = 0;
		R4 = 1;
		if (C1 == 0){
			key = 0x7F;
			c=8;
		}
		else if (C2 == 0){
			key = 0x67;
			c = 9;
		}
		else if (C3 == 0){
			key = 0x77;
			c = 0;
		}
		else if (C4 == 0){
			key = 0x7C;
			c = 0;
		}
		R1 = 1;
		R2 = 1;
		R3 = 1;
		R4 = 0;
		if (C1 == 0){
			key = 0x39;
			c = 0;
		}
		else if (C2 == 0){
			key = 0x5E;
			c = 0;
		}
		else if (C3 == 0){
			key = 0x79;
			c = 0;
		}
		else if (C4 == 0){
			key = 0x71;
			c = 0;
		}
	
}

void mode1(){
        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();
    return;
}

void mode2(){
        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
		switch_key();
        delay();
		switch_key();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 1;
		switch_key();
        delay();
		switch_key();
	
        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
	
        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
				
        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
				
        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 0;
				switch_key();
        delay();
				switch_key();
        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 1;
				switch_key();
        delay();
				switch_key();
    return;
}

void mode3(){
        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();
    return;
}


void mode4(){
        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 1;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

		return;
}


void main(){
		key = 0x00;
		R1 = 1;
		R2 = 1;
		R3 = 1;
		R4 = 1;
		ledpin1 = 0;
		ledpin2 = 0;
		ledpin3 = 0;
		ledpin4 = 0;

    while (1){
			switch_key();
			P0 = key;
      switch(c){
				case 1:
					ledpin1 = 1;
					switch_key();
					ledpin2 = 0;
					switch_key();
					ledpin3 = 0;
					switch_key();
					ledpin4 = 0;
					switch_key();
					delay();
					break;
				case 2:
					ledpin1 = 0;
					switch_key();
					ledpin2 = 1;
					switch_key();
					ledpin3 = 0;
					switch_key();
					ledpin4 = 0;
					switch_key();
					delay();
					break;
				case 3:
					ledpin1 = 0;
					switch_key();
					ledpin2 = 0;
					switch_key();
					ledpin3 = 1;
					switch_key();
					ledpin4 = 0;
					switch_key();
					delay();
					break;
				case 4:
					ledpin1 = 0;
					switch_key();
					ledpin2 = 0;
					switch_key();
					ledpin3 = 0;
					switch_key();
					ledpin4 = 1;
					switch_key();
					delay();
					break;
				case 5:
					mode1();
					switch_key();
					delay();
					break;
				case 6:
					mode3();
					switch_key();
					delay();
					break;
				case 7:
					mode2();
					switch_key();
					delay();
					break;
				case 8:
					mode4();
					switch_key();
					delay();
					break;
				case 9:
					ledpin1 = 0;
					switch_key();
					ledpin2 = 0;
					switch_key();
					ledpin3 = 0;
					switch_key();
					ledpin4 = 0;
					switch_key();
					delay();
					break;
				default:
					switch_key();
					c = 0;
					ledpin1 = 0;
					ledpin2 = 0;
					ledpin3 = 0;
					ledpin4 = 0;
			}
			
		}
}
	
	
