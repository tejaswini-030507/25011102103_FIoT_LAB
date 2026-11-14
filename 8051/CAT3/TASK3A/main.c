#include "modes.h"
#include "pins.h"

void main(){
    int mode=0;
    led1=led2=led3=led4=0;
    s_out=0;
    
    while(1){
        switch(mode){
            case 0:
                if(chkbutton()){
                    mode = 1;
                }
                break;
            case 1:
                mode1();
                mode++;
                break;
            case 2:
                mode2();
                mode++;
                break;
            case 3:
                mode3();
                mode++;
                break;
            case 4:
                mode4();
                mode=1;
                break;
            default:
                mode = 0;
                break;
        }
    }
}