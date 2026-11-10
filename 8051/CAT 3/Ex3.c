#include <reg51.h>
sbit ledpin1 = P1^0;
sbit ledpin2 = P1^1;
sbit ledpin3 = P1^2;
sbit ledpin4 = P1^3;
sbit button1 = P0^0;
sbit button2 = P0^4;

void delay(){
    int i,j;
    for(i=0;i<300;i++){
        for(j=0;j<300;j++){

        }
    }
}

void mode1(){
    while (button1 == 1){
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

    }
    return;
}

void mode2(){
    while(button1 == 1){
        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 1;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 0;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 1;
        delay();

        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();

        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 1;
        ledpin2 = 0;
        ledpin3 = 1;
        ledpin4 = 1;
        delay();

        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 0;
        delay();

        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 0;
        ledpin4 = 1;
        delay();

        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 0;
        delay();

        ledpin1 = 1;
        ledpin2 = 1;
        ledpin3 = 1;
        ledpin4 = 1;
        delay();
    }
    return;
}

void mode3(){
    while(button1 == 1){
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
    }
    return;
}

void mode4(){
    while(button1 == 1){
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
    }
		return;
}

void main(){
    int count = 0;
    int mode = 0;
	button2 = 0;
    while (1){
        if (button1 == 0){
           count += 1; 
           mode = count%4;
					while (button1 == 0){
								delay();
					}
				}

        else{
			switch(mode){
                case 0:
                   mode1();
                   break;
                case 1:
                   mode2();
									
                   break;
                case 2: 
                   mode3();
									
                   break;
                case 3:
                   mode4();
                   break;
								default:
									mode1();
            }
					}
			}
	}
	
