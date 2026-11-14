#include "delay.h"

void delay_loop(int a,int b){
    int i,j;
    for(i=0;i<a;i++){
        for(j=0;j<b;j++){

        }
    }
}

//Delay for 1Hz frequency
void delay_1Hz()
{
    delay_loop(300,300);
}

//Delay for any ms
void delay(int a)
{
    delay_loop(a,a);
}