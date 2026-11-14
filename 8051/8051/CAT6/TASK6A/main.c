#include <reg51.h>

void main(){
    //Configuring
    TMOD=0x20;
    TH1=0xFD;
    SCON=0x50;
    //Start timer
    TR1=1;
    //Transmission
    while(1){
        SBUF='A';
        while(TI==0);
        TI=0;
    }   
}
