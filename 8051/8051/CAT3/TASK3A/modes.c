#include "modes.h"
#include "delay.h"
#include "pins.h"

//Checking if Button is pressed or not
bit chkbutton(){
    if(button==0){
        while(button==0);
        return 1;
    }
    return 0;
}

//Running LED Mode
void mode1(){
    led1=led2=led3=led4=0;
    while(1){
        led1=1;
        delay_1Hz();
        led1=0;
        if(chkbutton()){
            return;
        }

        led2=1;
        delay_1Hz();
        led2=0;
        if(chkbutton()){
            return;
        }

        led3=1;
        delay_1Hz();
        led3=0;
        if(chkbutton()){
            return;
        }

        led4=1;
        delay_1Hz();
        led4=0;
        if(chkbutton()){
            return;
        }
    }
}

//Binary Counter Mode
void mode2(){
    led1=led2=led3=led4=0;
    while(1){
        led1=led2=led3=led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=led3=0;
        led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=led4=0;
        led3=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=0;
        led3=led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led3=led4=0;
        led2=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led3=0;
        led2=led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led4=0;
        led2=led3=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=0;
        led2=led3=led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led2=led3=led4=0;
        led1=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led4=1;
        led2=led3=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led3=1;
        led2=led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led3=led4=1;
        led2=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=1;
        led3=led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=led4=1;
        led3=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=led3=1;
        led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }
        led1=led2=led3=led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

    }
}

//Alternating Pattern Mode
void mode3(){
    led1=led2=led3=led4=0;
    while(1){
        led1=led3=1;
        led2=led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led2=led4=1;
        led1=led3=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }
    }
    
}

//All Led Flash Mode
void mode4(){
    led1=led2=led3=led4=0;
    while(1){
        led1=led2=led3=led4=1;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

        led1=led2=led3=led4=0;
        delay_1Hz();
        if(chkbutton()){
            return;
        }

    }
}